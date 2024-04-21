#include "map.h"
#include "myLib.h"
void createMap()
{
	for (int i = 20; i <= max_x - 40 ; i += 20)
	{
		for (int j = 20; j <= max_y - 40; j +=20)
		{
			if (i == 20 || i == max_x - 40 ||
				j == 20 || j == max_y - 40)
			{
				wall[size_wall] = { i,j, 40,40 };
				size_wall++;
			}
		}
	}
}

