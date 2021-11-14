#include <stdio.h>
#define MAXLINE 20

void print_length(char text[], int start, int end) {
    for (int i = start; i<end; i++) {
        putchar(text[i]);
    }
}

void fold() 
{
    int cn = 0;
    char c;
    char buffer[MAXLINE + 1];
    buffer[MAXLINE] = '\0';
    while((c = getchar()) != EOF)
        if (cn < MAXLINE) {
            buffer[cn++] = c;
            if (c == '\n') {
                print_length(buffer, 0, cn);
                cn = 0;
            }
        } else {
            // this bit doesn't work yet
            for (int i=MAXLINE; i>=0; i--) {
                if (buffer[i] == ' ' || buffer[i] == '\t') {
                    for (int j=0; j<i; j++) {
                        putchar(buffer[j]);
                    }
                    if (i == MAXLINE - 1)
                        putchar('\\');
                    putchar('\n');
                    for (int j=i; j<MAXLINE; j++) {
                        putchar(buffer[j]);
                    }
                    cn = 0;
                    break;
                } else {
                    if (i == 0) {
                        printf("%s", buffer);
                        cn = 0;
                    }
                }
            }
        }
}

int main()
{
    fold();
    return 0;
}
