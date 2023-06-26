#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#include"windows.h"

extern int min_n;
extern int max_n;
extern int element;
using namespace std;

DWORD WINAPI min_max(LPVOID params) { //线程1

	float minValue = FLT_MAX;
	float maxValue = FLT_MIN;

	for (int i = 0; i < element; i++) {
		if (minValue > ((float*)params)[i]) {
			minValue = ((float*)params)[i];
			min_n = i;
		}
		Sleep(7);
		if (maxValue < ((float*)params)[i]) {
			maxValue = ((float*)params)[i];
			max_n = i;
		}
		Sleep(7);
	}
	printf("\nMin:\n");
	printf("%f", minValue);
	printf("\nMax:\n");
	printf("%f\n", maxValue);
	return 0;
}

extern float av_val;
extern int element;


DWORD WINAPI average(LPVOID params) { //线程2
	av_val = 0;

	for (int i = 0; i < element; i++) {
		av_val += ((float*)params)[i];
		Sleep(12);
	}
	av_val /= element;
	printf("\n average: \n");
	printf("%f\n", av_val);
	return 0;
}

int min_n = 0;
int max_n = 0;
float av_val;
int element = 0;

int main() {
	printf("写数组大小 write array size\n");
	scanf_s("%i", &element);

	HANDLE* threadArray = (HANDLE*)calloc(element, sizeof(HANDLE));
	float* array = (float*)calloc(element, sizeof(float));

	for (int i = 0; i < element; i++) {
		float value = 0;

		printf("写入数组元素值 write array element value [%d]\n", i);
		scanf_s("%f", &value);
		array[i] = value;


	}

	HANDLE MinMaxThread = CreateThread(NULL, 0, min_max, array, 0, NULL);
	HANDLE AverageThread = CreateThread(NULL, 0, average, array, 0, NULL);

	DWORD WaitDorSingleObject(
		HANDLE hHandle,
		DWORD dwMilliseconds
	);

	WaitForSingleObject(MinMaxThread, INFINITE);
	WaitForSingleObject(AverageThread, INFINITE);
	CloseHandle(MinMaxThread);
	CloseHandle(AverageThread);

	array[min_n] = av_val;
	array[max_n] = av_val;
	for (int i = 0; i < element; i++)
	{
		//cout << array[i] << " ";
		printf("%f ", array[i]);
	}

	system("pause");
	return 0;
}



