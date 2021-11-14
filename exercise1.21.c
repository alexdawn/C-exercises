#include <stdio.h>
#define TABSPACES 4

void entab() 
{
	int cn = 0;
	char c;
	while((c = getchar()) != EOF)
	  	if (c != '\t') {
			putchar(c);
			cn++;
			if (c == '\n')
				cn = 0;
		} else {
			for(int i = 0; i < 4 - (cn % TABSPACES); i++) {
				putchar(' ');
				cn += TABSPACES;
			}
		}
}

int main()
{
	entab();
	return 0;
}
