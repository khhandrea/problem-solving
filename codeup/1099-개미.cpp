#include<iostream>
using namespace std;

/*
	if here = 2
		check!
		end
	else
		check!
		if right !1
			go right
		else if down !1
			go down
		else
			break;
*/

int main()
{
	short map[10][10],
	coord[2] = {1, 1},
	i, j;
	
	for(i=0; i<10; i++)
		for(j=0; j<10; j++)
			cin >> map[i][j];

	while(1)
	{
		if(map[coord[0]][coord[1]] == 2)
		{
			map[coord[0]][coord[1]] = 9;
			break;
		}
		else
		{
			map[coord[0]][coord[1]] = 9;
			if(map[coord[0]][coord[1]+1] != 1)
			{
				coord[1] += 1;
			}
			else if(map[coord[0]+1][coord[1]] != 1)
			{
				coord[0] += 1;
			}
			else
			{
				break;
			}
		}
	}
	
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
} 
