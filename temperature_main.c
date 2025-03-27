#include <stdio.h>
#include "temperature.h"

int main(int argc, char *argv[]) {
    float input_temp, converted_temp, temp_in_celsius;
    int input_scale, output_scale;

    printf("Temperature Conversion Utility\n\n");

    //prompt for input scale
    printf("Select input scale:\n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &input_scale);

    //prompt for temperature value
    printf("Enter the temperature value: ");
    scanf("%f", &input_temp);

    //invalid Kelvin check
    if (input_scale == 3 && input_temp < 0.0) {
        printf("Error: Kelvin cannot be negative.\n");
        return 1;
    }

    //prompt for target scale
    printf("Select target scale:\n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
    printf("3. Kelvin\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &output_scale);

    //check if input and output scales are the same
    if (input_scale == output_scale) {
        printf("Error: Cannot convert to the same scale.\n");
        return 1;
    }

    //convert input to Celsius
    if (input_scale == 1) {
        temp_in_celsius = fahrenheit_to_celsius(input_temp);
    } else if (input_scale == 2) {
        temp_in_celsius = input_temp;
    } else {
        temp_in_celsius = kelvin_to_celsius(input_temp);
    }

    //convert from Celsius to desired output scale
    if (output_scale == 1) {
        converted_temp = celsius_to_fahrenheit(temp_in_celsius);
        printf("Converted temperature: %.2f °F\n", converted_temp);
    } else if (output_scale == 2) {
        converted_temp = temp_in_celsius;
        printf("Converted temperature: %.2f °C\n", converted_temp);
    } else {
        converted_temp = celsius_to_kelvin(temp_in_celsius);
        printf("Converted temperature: %.2f K\n", converted_temp);
    }

    //categorize using Celsius value
    categorize_temperature(temp_in_celsius);

    return 0;
}
