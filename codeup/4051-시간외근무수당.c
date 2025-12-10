/* example
16.0 16.5
17.0 20.5
18.5 23.0
22.5 23.5
19.5 22.5
*/

#include<stdio.h>

int main()
{
	int i, money;
	float start, end, time, result=0.0;
	for(i=1; i<=5; i++)
	{
		scanf("%f %f", &start, &end);
		time = end - start;
		if(time >= 1.0) result += (time-1.0);
	}
	money = result * 10000;
	if(result >= 15) money *= 0.95;
	else if(result <= 5) money *= 1.05;
	printf("%d",money); 
	return 0;
}
