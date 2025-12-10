#include<iostream>
using namespace std;

int main()
{
	int n, i;
	cin >> n;
	for(i=1; i<n+1; i++)
	{
		if(i%3 != 0) cout << i << " ";
		else cout << "X ";
	}
	
	return 0;
}
