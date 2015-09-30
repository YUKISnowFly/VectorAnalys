#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "Fps.h"
#include "File.h"
#include "Block.h"

int main()
{
	const int
		maxRange = 300,
		blockSize = 5,
		blockNum = (maxRange * 2) / blockSize,
		frame = 60;

	File fileR, fileW;
	Vector3 pointClouds[12000];		//点群データ
	int countPoint = 0;				//点群の総数
	double aveY = 0.0, minX = 0.0, maxX = 0.0, minZ = 0.0, maxZ = 0.0;
	Block block[blockNum][blockNum];
	Fps fps;

	fileR.openRead("Result.txt");
	fileW.openWrite("Result3.txt");

	fps.Start();

	for (int j = 0; j < frame; j++)
	{
		for (int i = 0; i < 12000; i++)
		{
			pointClouds[i] = fileR.getVec();
			if (pointClouds[i].x == 0.0 &&
				pointClouds[i].y == 0.0 &&
				pointClouds[i].z == 0.0)
				break;
			else
			{
				countPoint++;
				//if (minX > pointClouds[i].x) minX = pointClouds[i].x;
				//else if (maxX < pointClouds[i].x) maxX = pointClouds[i].x;
				//if (minZ > pointClouds[i].z) minZ = pointClouds[i].z;
				//else if (maxZ < pointClouds[i].z) maxZ = pointClouds[i].z;
				//aveY += pointClouds[i].y;
				if (pointClouds[i].y > 3.0)
				{
					block[((int)pointClouds[i].x + maxRange) / blockSize][((int)pointClouds[i].z + maxRange) / blockSize].pointNum++;
				}
			}
		}
	}

	//オブジェクト位置の検索
	for (int i = 0; i < blockNum; i++)
	{
		for (int j = 0; j < blockNum; j++)
		{
			if (block[i][j].pointNum > 10)
			{
				//fprintf(fpa, "blockX = %d, blockY = %d\n", i, j);
				fileW.print("*");
			}
			else if (i == blockNum / 2 && j == blockNum / 2)
				fileW.print("o");
			else fileW.print(" ");
		}
		fileW.print("\n");
	}

	fps.End();

	printf("%dF = %fs\n", frame, fps.Get());
	printf("1F = %fs\n", fps.Get() / frame);


	fileR.close();

	/*
	for (int i = 0; i < 12; i++)
	{
		//printf("%d\n", (int)pointClouds[i].x + maxRange);
		printf("x = %f, y = %f, z = %f\n", pointClouds[i].x, pointClouds[i].y, pointClouds[i].z);
		printf("blockX = %d, blockZ = %d\n", ((int)pointClouds[i].x + maxRange) / blockSize, ((int)pointClouds[i].z + maxRange) / blockSize);
	}
	*/
	
	//aveY /= countPoint;

	/*for (int i = 0; i < countPoint; i++)
	{
		int
			tempX = ((int)pointClouds[i].x % blockNum) + blockNum,
			tempZ = ((int)pointClouds[i].z % blockNum) + blockNum;
		block[tempX][tempZ].insert(aveY - pointClouds[i].y);
	}*/

	/*
	//簡易危険マップ作製
	for (int i = 0; i < blockNum; i++)
	{
		for (int j = 0; j < blockNum; j++)
		{
			if (block[i][j].pointNum > 10)
			{
				//fprintf(fpa, "blockX = %d, blockY = %d\n", i, j);
				fileW.print("*");
			}
			else if (i == blockNum / 2 && j == blockNum / 2)
				fileW.print("o");
			else fileW.print(" ");
		}
		fileW.print("\n");
	}
	*/
	

	fileW.close();

	getchar();
	return 0;
}