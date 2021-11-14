#include <stdio.h>

main()
{
    int c;
    do (c = getchar() != EOF) {
        printf("%d", c);
    }
}
