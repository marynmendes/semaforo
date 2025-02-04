#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" //biblioteca para gereciamento de temporizadores de hardware

#define led_red 13 //luz vermelha
#define led_yellow 12 //led amarelo (na placa BitDogLab será azul)
#define led_green 11 // luz verde

//variáveis para indicar situação de cada led
bool led_red_on = true;
bool led_yellow_on = false;
bool led_green_on = false;

//função callback que será chamada repetidamente
bool repeating_timer_callback(struct  semaforo *t)
{
    if(led_red_on == true){
        gpio_put(led_red, led_red_on);
        led_red_on = !led_red_on;
        led_yellow_on = true;
    } else if (led_yellow_on == true){
        gpio_put(led_yellow, led_yellow_on);
        led_yellow_on = !led_yellow_on;
        led_green_on = true;
    } else if (led_green_on == true){
        gpio_put(led_green, led_green_on);
        led_green_on = !led_green_on;
        led_red_on = true;
    }
   return true; 
};

int main()
{
    stdio_init_all();

    //inicialização de cada led
    gpio_init(led_red);
    gpio_init(led_yellow);
    gpio_init(led_green);

    //configuração dos leds como saída
    gpio_set_dir(led_red, true);
    gpio_set_dir(led_yellow, true);
    gpio_set_dir(led_green, true);

    //declaração de uma estrutura de temporizador de repetição
    struct repeating_timer timer;

    //configuração do temporizador para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    //Mensagem que aparecerá no monitor serial a cada um segundo
    while (true) {
        sleep_ms(1000);
        printf("1 segundo se passou.\n");
        
    }
}
