#include<iostream>
using namespace std;

int main()
{
	int n, i;
	char c;
	
	cin >> c;
	
	switch(c)
	{
		case 'A' :
			n = 10;
			break;
		case 'B' :
			n = 11;
			break;
		case 'C' :
			n = 12;
			break;
		case 'D' :
			n = 13;
			break;
		case 'E' :
			n = 14;
			break;
		default :
			n = 15;
			break;
	}
	for(i=1; i<15+1; i++)
	{
		printf("%X*%X=%X\n", n, i, n*i);
	}
	
	return 0;
}
