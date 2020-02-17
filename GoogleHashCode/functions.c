#include "Header.h"

char choose_dataset(void)
{
	char userchoice = '\0';
	printf("\t\t\tdataset (a)\n\t\t\tdataset (b)\n\t\t\tdataset (c)\n\t\t\tdataset /*(d)\n\t\t\tdataset (e)\n");
	printf("\nPlease choose a data set by entering a letter: ");
	scanf(" %c", &userchoice);
	return userchoice;
}

int read_data(FILE* infile)
{
	int datapoint = 0;
	fscanf(infile, "%d", &datapoint);
	printf("datapoint = %d\t", datapoint);
	return datapoint;
}

void reorganize_data(FILE* infile, FILE* outfile, int counter)	// READ AND RE-ORGANIZE DATA TO DESCENDING ORDER
{	
	// USE ARRAY TO SORT DATASET
	int datapoint = 0;
	fscanf(infile, "%d", &datapoint);
	for (size_t i = 0; i < counter; i++)
	{
		
	}

	//printf("datapoint = %d\t", datapoint);
	//fprintf(outfile, "%d ", datapoint);
}