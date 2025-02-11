# Controle de Servo Motor com PWM no Raspberry Pi Pico

## Descrição do Projeto
Este projeto controla um servo motor utilizando a placa Raspberry Pi Pico e um sinal PWM. O código configura a GPIO 22 (ou outra GPIO, como a 12, para testes na placa BitDogLab) para gerar um sinal PWM com frequência de 50Hz, permitindo o controle preciso da posição do servo motor.

## Requisitos
- Placa Raspberry Pi Pico ou BitDogLab
- Servo motor compatível com PWM


## Conexões
### Para o Raspberry Pi Pico:
- **Servo Motor:**
  - Fio **vermelho** (VCC) → 5V
  - Fio **preto/marrom** (GND) → GND
  - Fio **azul** (Sinal) → GPIO 22

## Funcionamento
1. Configura a GPIO do servo para funcionar como saída PWM.
2. Define um ciclo ativo para cada posição do servo:
   - **0°**: Pulso de 500µs
   - **90°**: Pulso de 1470µs
   - **180°**: Pulso de 2400µs
3. Move o servo para cada uma dessas posições e espera 5 segundos.
4. Entra em um loop de movimentação contínua, variando o ângulo de 0° a 180° em pequenos incrementos para um movimento suave.

## Como Usar na placa
1. Troque a macro do pino 22 para 12
2. Compile e carregue o código na placa Raspberry Pi Pico usando o SDK do Raspberry Pi Pico.
3. Execute o programa e observe a mudança no LED.

---
**Autor:** João Pedro Ferreira de Jesus


