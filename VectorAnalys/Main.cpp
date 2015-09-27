#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "FileRead.h"
#include "Block.h"

int main()
{
	const int
		maxRange = 300,
		blockNum = maxRange / 10;

	File file;
	Vector3 pointClouds[12000];
	int countPoint = 0;
	double aveY = 0.0, minX = 0.0, maxX = 0.0, minZ = 0.0, maxZ = 0.0;
	Block block[blockNum * 2][blockNum * 2];

	file.open("Result.txt");

	for (int i = 0; i < 12000; i++)
	{
		pointClouds[i] = file.getVec();
		if (pointClouds[i].x == 0.0 &&
			pointClouds[i].y == 0.0 &&
			pointClouds[i].z == 0.0)
			break;
		else
		{
			//if (minX > pointClouds[i].x) minX = pointClouds[i].x;
			//else if (maxX < pointClouds[i].x) maxX = pointClouds[i].x;
			//if (minZ > pointClouds[i].z) minZ = pointClouds[i].z;
			//else if (maxZ < pointClouds[i].z) maxZ = pointClouds[i].z;
			//aveY += pointClouds[i].y;
			if (pointClouds[i].y > 5.0)
			{
				block[((int)pointClouds[i].x + maxRange) % blockNum][((int)pointClouds[i].z + maxRange) % blockNum].pointNum++;
				countPoint++;
			}
		}
	}

	file.close();
	
	//aveY /= countPoint;

	/*for (int i = 0; i < countPoint; i++)
	{
		int
			tempX = ((int)pointClouds[i].x % blockNum) + blockNum,
			tempZ = ((int)pointClouds[i].z % blockNum) + blockNum;
		block[tempX][tempZ].insert(aveY - pointClouds[i].y);
	}*/
	
	FILE* fpa;
	fpa = fopen("Result2.txt", "w");

	for (int i = 0; i < blockNum; i++)
	{
		for (int j = 0; j < blockNum; j++)
		{
			if (block[i][j].pointNum > 5) fprintf(fpa, "x = %d, y = %d\n", i, j);
		}
	}
	printf("%d\n", countPoint);
	fclose(fpa);

	getchar();
	return 0;
}