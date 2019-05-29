#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp = fopen("program.txt", "r");
	if(fp==NULL)
	{
		printf("error");
		exit(1);
	}
	int num;
	fscanf(fp, "%d", &num);
	printf("%d\n", num);
}
