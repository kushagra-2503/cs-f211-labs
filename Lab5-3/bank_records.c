#include "bank_records.h"

FILE* openFile(char* filename, char* mode)
{
    FILE* fp = fopen(filename, mode);
    if(fp==NULL)
    {
        printf("Error\n");
        exit(1);
    }
    return fp;
}

Card createRecord(){
    Card c = malloc(sizeof(struct credit_card));
    return c;
}

Card* storeRecords(char* filename, int initial_size)
{
    FILE* fp = openFile(filename, "r");
    int size  = initial_size;
    int num_records = 0;
    long long int num;
    char bank_code[6],exp_date[8], fname[20], lname[20]; 
    Card* arr = malloc(sizeof(Card)*initial_size);
    for(int  i = 0; i < initial_size; i++)
    {
        arr[i] = createRecord();
    }
    while(fscanf(fp, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n",&num, bank_code, exp_date, fname, lname)!=EOF){
        if(num_records == size)
        {
            arr = realloc(arr, sizeof(Card)* size*2);
            for(int  k = size; k < 2*size; k++)
            {
                arr[k] =  createRecord();
            }
            size*=2;
        }
        arr[num_records]->num = num;
        strcpy(arr[num_records]->bank_code,bank_code);
        strcpy(arr[num_records]->exp_date, exp_date);
        strcpy(arr[num_records]->fname, fname);
        strcpy(arr[num_records]->lname, lname);
        num_records++;
    }
    return arr;
}
