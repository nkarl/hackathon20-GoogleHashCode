#include "Header.h"

// ASKS USER TO CHOOSE ONE LETTER CORRESPONDING TO A DATA-SET.
char choose_dataset(void)
{
	char userchoice = '\0';
	printf("\t\t\tdataset (a)\n\t\t\tdataset (b)\n\t\t\tdataset (c)\n\t\t\tdataset (d)\n\t\t\tdataset (e)\n");
	printf("\nPlease choose a data set by entering a letter: ");
	scanf(" %c", &userchoice);
	return userchoice;
}

// READS ONE DATA-POINT FROM INPUT FILE WHEN INVOKED. MEANT TO BE RECYCLED IN LOOPS.
int read_data(FILE* infile)
{
	int datapoint = 0;
	fscanf(infile, "%d", &datapoint);
	return datapoint;
}