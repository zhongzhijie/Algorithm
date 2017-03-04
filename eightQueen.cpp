// eightQueen.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>

#define QUEEN_COUNT 8

int resolve = 0;
int *queenArray;

int placeRight(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (queenArray[i] == queenArray[k] || abs(queenArray[i] - queenArray[k]) == abs(i - k))
			return 0;
	}
	return 1;
}

int backtrace(int k)
{
	int i = 0;
	for (i = 0; i < QUEEN_COUNT; i++)
	{
		queenArray[k] = i;	/* 第k+1个皇后放在第i+1列 */
		if (placeRight(k))
		{
			if (k == QUEEN_COUNT - 1)
			{
				resolve++;
				return 0;
			}
			backtrace(k + 1);
		}
	}
}

int main()
{
	queenArray = new int[QUEEN_COUNT];

	backtrace(0);	/* 从第1（下标为0）个皇后开始放置 */
	printf("%d\r\n", resolve);
	delete queenArray;

    return 0;
}

