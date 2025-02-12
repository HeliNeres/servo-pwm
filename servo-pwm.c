#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define SERVO_PIN 22 //pino do LED conectado a GPIO como PWM

const uint pwm_freq = 50;
const uint clk_freq = 125*1000000;
const float divisor = 125.0;

uint16_t wrap = clk_freq/(divisor*pwm_freq);

const uint passo = 5;
uint nivel = 500;

//rotina principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, divisor); //define o divisor de clock do PWM

    pwm_set_wrap(slice, wrap); //definir o valor de wrap

    pwm_set_gpio_level(SERVO_PIN, nivel); //definir o ciclo de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

    uint sentido = 1;

    //loop principal
    while (true) {
        //printf("level: %d\n", nivel);
        pwm_set_gpio_level(SERVO_PIN, nivel);

        if(nivel==2400){
            printf("180 graus\n");
            sleep_ms(5000);
        }else if(nivel==1470){
            printf("90 graus\n");
            sleep_ms(5000);
        }else if(nivel==500){
            printf("0 graus\n");
            sleep_ms(5000);
        }

        if(sentido){
            nivel +=passo;
        }else{
            nivel -=passo;
        }

        if(nivel>=2400) sentido = 0;
        if(nivel<=500) sentido = 1;

        sleep_ms(10);
    }
}