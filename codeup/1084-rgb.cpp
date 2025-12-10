#include<iostream>
using namespace std;

int main()
{
	int a, b, c, i, j, k, count=0;
	cin >> a >> b >> c;
	
	for(i=0; i<a; i++)
		for(j=0; j<b; j++)
			for(k=0; k<c; k++)
			{
				printf("%d %d %d\n", i, j, k);
				count ++;
			}
				
				
	cout << count;
	
	return 0;
}
