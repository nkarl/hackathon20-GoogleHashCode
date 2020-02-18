#include "Header.h"

char choose_dataset(void)
{
	char userchoice = '\0';
	printf("\t\t\tdataset (a)\n\t\t\tdataset (b)\n\t\t\tdataset (c)\n\t\t\tdataset (d)\n\t\t\tdataset (e)\n");
	printf("\nPlease choose a data set by entering a letter: ");
	scanf(" %c", &userchoice);
	return userchoice;
}

int read_data(FILE* infile)
{
	int datapoint = 0;
	fscanf(infile, "%d", &datapoint);
	return datapoint;
}

void reorganize_datasetA(FILE* infile, FILE* outfile, int counter)	// READS AND RE-ORGANIZES DATA IN DESCENDING ORDER.
{	
	// DELCARES A DYNAMIC ARRAY AND INITIALIZES ITS SIZE WITH POINTER TO THE VARIABLE <counter>
	int* array_raw = NULL;
	array_raw = malloc(sizeof(int) * counter);
	int i, j, temp;
	int rawdata = 0;

	printf("\n\tRAW DATA: ");

	// FIRST: SCANS IN DATA POINT-BY-POINT AND ALLOCATES TO ASCENDING BLOCKS IN DECLARED ARRAY.
	for (i = 0; i < counter; i++)
		{
			rawdata = read_data(infile);
			array_raw[i] = rawdata;
			printf("[%d]:%d  ", i, array_raw[i]);
			fprintf(outfile, "[%d]:%d  ", i, array_raw[i]);

			/*for (j = i + 1; j < setAmax; j++)
			{
				if (array_raw[i] > array_raw[j])
				{
					temp = array_raw[i];
					array_raw[i] = array_raw[j];
					array_raw[j] = temp;
					printf("%d ", array_raw[i]);
					fprintf(outfile, "%d ", array_raw[i]);
				}
			}*/
		}

	printf("\n");
	//printf("datapoint = %d\t", datapoint);
	//fprintf(outfile, "%d ", datapoint);
}