#include <stdio.h>

float fahr_to_celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("fahr\tcelsius\n");
    while(fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}
