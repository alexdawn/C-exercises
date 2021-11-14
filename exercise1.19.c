#include <stdio.h>
#define MAXLINE 1000

int mgetline(char s[], int lim)
{
    int c, i, l;
    i = l = 0;
    while ((c=getchar()) != EOF && c!= '\n') {
        if (i < lim - 1)
            s[l] = c;
            //printf("in text %d", l);
            ++l;
        ++i;
    }
    if (c == '\n') {
        s[l] = c;
        //printf("EOL %d", l);
        ++i;
        ++l;
    }
    s[l] = '\0';
    //printf("string %s", s);
    return i;
}

int string_length(char text[]) {
    int i = 0;
    while (text[i++] != '\0')
        ;
    return i;
}

int reverse(char from[])
{
    for (int i = string_length(from) - 1; i >= 0; --i)
        if (from[i] != '\n' && from[i] != '\0')
            putchar(from[i]);
    putchar('\n');
}

void exercise() 
{
    int len;
    char line[MAXLINE];
    while ((len = mgetline(line, MAXLINE)) > 0)
        if (len > 1)
            reverse(line);
}


int main()
{
    exercise();
    return 0;
}
