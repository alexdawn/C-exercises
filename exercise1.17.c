#include <stdio.h>
#define MAXLINE 1000
#define LINTLENGTH 20

int mgetline(char line[], int maxline);

int main()
{
    int len, ln;
    ln = 0;
    char line[MAXLINE];
    while ((len = mgetline(line, MAXLINE)) > 0) {
        ln++;
        if (len > LINTLENGTH) {
            printf("line %d has %d charecters (max %d)\n%s\n", ln, len, LINTLENGTH, line);
        }
    }
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
