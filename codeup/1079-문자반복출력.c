#include<stdio.h>

int main()
{
	char c;
	while(1)
	{
		scanf("%c", &c);
		if (c != ' ') printf("%c\n", c);
		if(c == 'q') break;
	}
	
	return 0;
}
