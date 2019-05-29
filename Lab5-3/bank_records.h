#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
struct credit_card{
    long long int num;
    char bank_code[6];
    char exp_date[8];
    char fname[20];
    char lname[20];
};
typedef struct credit_card* Card;
int* topofstack;
Card createRecord();
FILE* openFile(char* filename, char* mode);
Card* storeRecords(char* filename, int initial_size);
