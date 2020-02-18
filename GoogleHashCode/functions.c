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

// READS AND RE-ORGANIZES DATA IN DESCENDING ORDER.
void reorganize_dataset(FILE* infile, FILE* outfile1, FILE* outfile2, int num_types)
{	
	// DELCARES TWO DYNAMIC ARRAYS AND INITIALIZES THEIRS SIZE WITH <NULL>
	int* array1 = NULL, * array2 = NULL;
	
	// INITIALIZES POINTER TO THE VARIABLE <num_types>
	array1 = malloc(sizeof(int) * num_types);
	array2 = malloc(sizeof(int) * num_types);

	// DECLARES VARIABLES: <num_types> AND <datapoint> TO STORE A SCANNED-IN ENTRIES ONE AT A TIME INTO A BLOCK IN ARRAYS
	int i = 0, j = 0, rawdata = 0;

	printf("\nRAW DATA, [size = %d]\t: \n\n", num_types);

	// FIRST: SCANS IN DATA POINT-BY-POINT AND ALLOCATES TO ASCENDING BLOCKS IN <array1>.
	for (i = 0; i < num_types; i++)
	{
		rawdata = read_data(infile);
		array1[i] = rawdata;
		fprintf(outfile1, "%d	", array1[i]);
	}

	// SECOND: STREAM DATA FROM <array1> TO <array2>
	i = 0;
	for (j = num_types - 1; j >= 0; j--)
	{
		array2[j] = &array1[i];
		printf("%d	", array1[j]);
		fprintf(outfile2, "%d	", array1[j]);
	}

	printf("\n");
	free(array1);
	free(array2);
}

// ADDS INCREMENTALLY DOWN THE NEW RAWDATA LIST. TERMINATE CONDITION: sum > max
int get_slices(FILE* infile1, FILE* infile2, int max, int num_types)
{
	int* array = NULL;

	array = malloc(sizeof(int) * num_types);

	int i = 0, j = 0, types = 0, sum = 0, rawdata = 0;

	printf("\nCONDITION\t\t: [max = %d]\t[size = %d]\n\nSELECTED DATA BELOW\t:\n\n", max, num_types);

	while (sum < max)
	{
		rawdata = read_data(infile2);
		array[i] = rawdata;
		sum = sum + rawdata;
		i = i++;
		types = i;
		if (sum > max)
		{
			i = i - 1;
			sum = sum - array[i];
			types = i;
			//printf("rawdata = %d ", rawdata);		// IGNORE, for debugging purpose.
			break;			
		}
		printf("%d	", rawdata);
	}

	while (sum < max)
	{
		rawdata = read_data(infile1);
		array[j] = rawdata;
		//printf("rawdata = %d ", rawdata);		// IGNORE, for debugging purpose.
		sum = sum + rawdata;
		j = j++;
		types = types++;

		if (sum > max)
		{
			j = j - 1;
			sum = sum - array[j];
			types = types - 1;
			//printf("rawdata = %d ", rawdata);		// IGNORE, for debugging purpose.
			break;
		}
		printf("%d	", rawdata);
	}

	printf("\n\nRESULT\t\t\t: [SLICES < max] = %d\t[TYPES < size] = %d\n", sum, types);

	return sum;
}