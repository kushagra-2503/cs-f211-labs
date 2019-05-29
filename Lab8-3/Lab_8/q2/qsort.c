#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName)
{
	FILE* fp = fopen(fileName, "r");
	fscanf(fp, "%d", &size);
	int* arr = malloc(sizeof(int)* size);
	char name[11];
	int marks;
	int i = 0;
	for(int i = 0 ; i  <size; i++){
	fscanf(fp, "%s%d", name, &marks);
		arr[i] = marks;
	}
	return arr;
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	int* arr = malloc(sizeof(int)*(hiKey-loKey+1));
	arr[0] = 0;
	int count = 0;
	for(int i = 0; i < lsSize; i++)
	{
		if(arr[Ls[i]-loKey]==0)
		{
			arr[Ls[i]-loKey] = 1;
			count++;
		}
	}
	KeyStruct keys =  malloc(sizeof(struct keyStruct));
	keys->Keys = malloc(sizeof(int)*count);
	keys->keysSize = count;
	int j = 0;
	for(int i = 0; i < hiKey-loKey+1;i++)
	{
		if(arr[i]==1)
		{
			keys->Keys[j] = i + loKey;
			j++;
		}
	}
	return keys;
}

int part2Loc(int* Ls, int lo, int hi, int piv)
{
	int i;
	for(i = lo; i <= hi ;i++)
	{
		if(Ls[i] == piv)
		{
			break;
		}
	}
	int temp;
	temp = Ls[i];
	Ls[i] = Ls[hi];
	Ls[hi] = temp;
	i = lo-1;
	int j = 0;
	while(j<hi){
		if(Ls[j] <= piv)
		{
			i++;
			temp = Ls[j];
			Ls[j] = Ls[i];
			Ls[i] = temp;
		}
		j++;
	}
	temp = Ls[hi];
	Ls[hi] =Ls[i+1];
	Ls[i+1] = temp;
	return i+1;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct keys = extractKeys(Ls, size,loKey, hiKey);
	for(int i = 0 ; i  < keys->keysSize-1;i++)
	{
		part2Loc(Ls, 0, size-1, keys->Keys[i]);
	}
}