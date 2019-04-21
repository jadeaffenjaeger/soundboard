#include "gpio.h"

static volatile struct gpio_t * gpio_A = (struct gpio_t *) GPIOA_BASE;
static volatile struct gpio_t * gpio_B = (struct gpio_t *) GPIOB_BASE;
static volatile struct gpio_t * gpio_C = (struct gpio_t *) GPIOC_BASE;
static volatile struct gpio_t * gpio_D = (struct gpio_t *) GPIOD_BASE;
static volatile struct gpio_t * gpio_E = (struct gpio_t *) GPIOE_BASE;
static volatile struct gpio_t * gpio_F = (struct gpio_t *) GPIOF_BASE;


void gpio_init() {
    /* Init LED Pin*/
    gpio_B->DDR = (1 << P5);
    gpio_B->CR1 = (1 << P5);

    /* Init MOSFET Pin*/
    gpio_C->DDR = (1 << P7);
    gpio_C->CR1 = (1 << P7);
}

/*
 * LED
 *
 * LED is active LOW, so it's on when the Pin is LOW
 */
void gpio_led_on() {
    gpio_B->ODR &= ~(1 << P5);
}

void gpio_led_off() {
    gpio_B->ODR |= (1 << P5);
}

void gpio_led_toggle() {
    gpio_B->ODR ^= (1 << P5);
}

/*
 * DFPlayer on/off MOSFET
 *
 * DFPlayer consumes too much power, even when sleeping, so we turn
 * it off completely instead via an external MOSFET.
 */

void gpio_fet_on() {
    gpio_C->ODR |= (1 << P7);
}

void gpio_fet_off() {
    gpio_C->ODR &= ~(1 << P7);
}

// Not really needed, but handy for testing
void gpio_fet_toggle() {
    gpio_C->ODR ^= (1 << P7);
}

