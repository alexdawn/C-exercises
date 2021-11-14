#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = mgetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%d: %s", max, longest);
    return 0;
}

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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    //printf("%s => %s\n", from, to);
    while ((to[i] = from[i]) != '\0')
        ++i;
}
