#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int w, h, b;
	double result;
	cin >> w >> h >> b;
	
	result = w / 1024.0;
	result *= h;
	result /= 1024.0;
	result *= b;
	result /= 8;
	
	result = round(result * 100);
	result /= 100;
	
	printf("%.2f MB", result );
	
	return 0;
}
