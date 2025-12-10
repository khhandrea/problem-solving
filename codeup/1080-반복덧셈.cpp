#include<iostream>
using namespace std;

int main()
{
	int n, i, sum = 0;
	cin >> n;
	for(i=0; sum<n; i++)
	{
		sum += i;
	}
	cout << i-1;
	
	return 0;
}
