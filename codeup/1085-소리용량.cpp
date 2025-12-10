#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int h, b, c, s;
	double result;
	cin >> h >> b >> c >> s;
	result = h / 1024.0;
	result *= b;
	result /= 8;
	result *= c;
	result *= s;
	result /= 1024;
	
	result = round(result * 10);
	result /= 10;
	
	cout << result << " MB";
	
	
	
	return 0;
}
