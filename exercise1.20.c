#include <stdio.h>
#define TABSPACES 4

void detab() 
{
	char c;
	while((c = getchar()) != EOF)
		if (c != '\t')
			putchar(c);
		else
			for(int i = 0; i < TABSPACES; i++)
				putchar(' ');
}

int main()
{
	detab();
	return 0;
}
