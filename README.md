=== Projeto EmbarcaTech ===
ATIVIDADE 1: Semáforo

Com o emprego da função add_repeating_timer_ms(), presente
na ferramenta Pico SDK, foi projetado um semáforo com
temporização de 3 segundos para cada alteração de sinal.

O projeto pôde ser simulado com ajuda da plataforma wokwi, utilizando
1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (vermelho, amarelo e verde).
3) 03 Resistores de 330 Ω.

O acionamento do semáforo e a troca das luzes ocorre com o uso da função
de callback de temporizador e, enquanto isso ocorre, a mensagem
"1 segundo se passou." é exibida a cada segundo.
