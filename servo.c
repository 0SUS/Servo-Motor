#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"


#define SERVO_PIN           22         //pino onde o servo está conectado, no teste na placa bitdoglab é so trocar esse valor por 12
#define SERVO_FREQUENCY     50.0       //frequência do PWM em Hz
#define PWM_WRAP_VALUE      20000      //valor de wrap do PWM, determinando o período do sinal
#define PWM_CLOCK_DIVIDER   (125000000.0 / (PWM_WRAP_VALUE * SERVO_FREQUENCY))  //calcula o divisor de clock para alcançar 50Hz

//função para configurar o PWM no pino do servo
void configure_pwm() 
{
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); //define a função do pino como PWM
    uint slice_index = pwm_gpio_to_slice_num(SERVO_PIN); //pega o slice PWM do pino

    pwm_set_clkdiv(slice_index, PWM_CLOCK_DIVIDER); //configura o divisor de clock 
    pwm_set_wrap(slice_index, PWM_WRAP_VALUE);      //define o valor de wrap
    pwm_set_enabled(slice_index, true);            //ativa o PWM
}

//função para ajustar o duty cycle do PWM
void adjust_pwm_signal(uint16_t pulse_width) 
{
    pwm_set_gpio_level(SERVO_PIN, pulse_width); 
}

//função para mover o servo para um ângulo específico
void position_servo(float angle, uint16_t delay_time) 
{
    //converte o ângulo desejado para o valor correspondente de largura de pulso
    uint16_t pulse_width = 500 + (angle / 180.0) * (2400 - 500);

    adjust_pwm_signal(pulse_width); //ajusta o PWM 
    sleep_ms(delay_time);         
}

//função para movimentar o servo suavemente entre 0 e 180 graus
void servo_sweep_motion() 
{
    //move o servo de 0 a 180 graus de forma gradual
    for (float angle = 0; angle <= 180; angle += 1) 
    {
        position_servo(angle, 10); //incrementa o ângulo e espera 10ms para suavizar o movimento
    }
    
    //move o servo pro outro lado dessa vez
    for (float angle = 180; angle >= 0; angle -= 1) 
    {
        position_servo(angle, 10);
    }
}

int main() 
{
    configure_pwm(); 

    //move o motor pra três posições diferentes e espera 5 segundos
    position_servo(180, 5000); 
    position_servo(90, 5000);  
    position_servo(0, 5000);   

    //testando na placa com o led é so substituir o PINO 22 pelo 12
    
    while (true) 
    {
        servo_sweep_motion(); //executa o movimento
    }

    return 0;
}
