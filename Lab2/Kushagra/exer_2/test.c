#include <stdio.h>
#include<string.h>
int main(int argc, char* argv[])
{	
	//char prog_name[] =argv[0];
	for(int i=2;i<strlen(argv[0]);i++)
	{
		printf("%c", argv[0][i]);
	}
	printf(" ");
	for(int i=1;i<argc;i++)
		printf("%s ", argv[i]);
	printf("\n");
}
