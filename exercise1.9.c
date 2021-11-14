#include <stdio.h>
# define false 0
# define true 1

main()
{
    int c;
    int wasLastSpace = false;
    while ((c = getchar()) != EOF) {

        if (c == ' ' && wasLastSpace == false) {
            putchar(c);
            wasLastSpace = true;
        } else if (c != ' ') {
            wasLastSpace = false;
            putchar(c);

        }
    }
}
