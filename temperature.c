#include <stdio.h>
#include "temperature.h"

// convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// convert celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// convert kelvin to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// categorize the temperature and give advisory
void categorize_temperature(float celsius) {
    printf("Category: ");

    if (celsius < 0.0) {
        printf("Freezing - Wear a heavy coat.\n");
    } else if (celsius < 10.0) {
        printf("Cold - Wear a jacket.\n");
    } else if (celsius < 25.0) {
        printf("Comfortable - Enjoy your day.\n");
    } else if (celsius < 35.0) {
        printf("Hot - Stay hydrated.\n");
    } else {
        printf("Extreme Heat - Stay indoors!\n");
    }
}
