#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" //biblioteca para gereciamento de temporizadores de hardware

#define led_red 13 //luz vermelha
#define led_yellow 12 //led amarelo (na placa BitDogLab será azul)
#define led_green 11 // luz verde

//variáveis para indicar situação de cada led
bool led_red_on = false;
bool led_yellow_on = false;
bool led_green_on = false;



int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
