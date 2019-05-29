compileAll: bank_records.o main.o insertionSort.o
	gcc bank_records.o main.o insertionSort.o

bank_records.o: bank_records.c bank_records.h insertionSort.h
	gcc -c bank_records.c

main.o: main.c insertionSort.h bank_records.h
	gcc -c main.c

insertionSort.o: insertionSort.c bank_records.h insertionSort.h
	gcc -c insertionSort.c 
