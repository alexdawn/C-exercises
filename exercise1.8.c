#include <stdio.h>

main()
{
    int c;
    int newlines = 0;
    int spaces = 0;
    int tabs = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == '\n')
            ++newlines;
        if (c == ' ')
            ++spaces;
        if (tabs == '\t')
            ++tabs;
    }
    printf("\n");
    printf("newlines:\t%d\n", newlines);
    printf("spaces:\t%d\n", spaces);
    printf("tabs:\t%d\n", tabs);
}
