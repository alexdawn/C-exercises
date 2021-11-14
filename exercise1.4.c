#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 200;
    step = 10;

    celsius = lower;
    printf("fahr\tcelsius\n");
    while(celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        celsius += step;
    }
}
