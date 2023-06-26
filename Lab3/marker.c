#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "Threadstatus.h"

extern int* array;
extern int arraySize;
extern enum threadStatus* threadStatuses;
extern int threadCount;
  LPCRITICAL_SECTION* section;

void WINAPI marker(LPVOID params)
{
	int threadIndex = (int)params - 1;
	srand(threadIndex + 1);
	printf("номер %d 开始\n", threadIndex + 1);//带有数字的线程 
	while (1)
	{
		while (threadStatuses[threadIndex] != active) {}
		int markedElementsCount = 0;
		while (2 + 2 == 4)
		{
			int digit = rand();
			digit %= arraySize;
			EnterCriticalSection(&section);
			if (array[digit] == 0)
			{
				markedElementsCount++;
				Sleep(5);
				array[digit] = threadIndex + 1;
				Sleep(5);
			}
			else
			{
				printf("число: %d\n 布尔值： %d\n",
					threadIndex + 1, markedElementsCount, digit);
				threadStatuses[threadIndex] = paused;
				LeaveCriticalSection(&section);
				break;
			}
			LeaveCriticalSection(&section);
		}
		while (threadStatuses[threadIndex] == paused) {}

		if (threadStatuses[threadIndex] == finishing)
		{
			for (int i = 0; i < arraySize; ++i)
			{
				if (array[i] == threadIndex + 1)
				{
					array[i] = 0;
				}
			}
			threadStatuses[threadIndex] = finished;
			break;
		}
	}

}