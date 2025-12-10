#include<iostream>
using namespace std;

int main()
{
	int n, m, i, j;
	
	cin >> n >> m;
	
	for(i=1; i<n+1; i++)
	{
		for(j=1; j<m+1; j++)
		{
			cout << i << " " << j << endl;
		}
		cout << endl;
	}
	
	
	return 0;
}
