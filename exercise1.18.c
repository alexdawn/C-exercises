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

int trailing_trim(char to[], char from[])
{
    int i, length;
    int regular_text = 0;
    for (i = string_length(from) - 1; i >= 0; --i) {
        if (!regular_text && 
                !(from[i] == '\t' || 
                from[i] == ' ' || 
                from[i] == '\n' || 
                from[i] == '\0')) {
            regular_text = 1;
            length = i;
            to[i+1] = '\n';
            to[i+2] = '\0';
        }
        if (regular_text == 1)
            to[i] = from[i];
    }
    return length;
}

void exercise()      
{
    int len, len2;
    char line[MAXLINE];
    char trimed[MAXLINE];
    while ((len = mgetline(line, MAXLINE)) > 0) {           
        if (len > 1) {
            len2 = trailing_trim(trimed, line);
            for (int i = 0; trimed[i] != '\0'; i++)
                putchar(trimed[i]);
        }
    }    
}


int main()
{
    exercise();
    return 0;
}
