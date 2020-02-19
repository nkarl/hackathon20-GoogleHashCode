/**********************************************************************************************************************
	PROJECT: GOOGLE HASHCODE | JUDGE SYSTEM
	TEAM: COUGARS RAWR: 3, MEMBERS: KARL-ALBERT
									ROGUE_RUSSIAN
									WENZHI ZHUANG
	PROBLEM STATEMENT: Order the max_slicesimum number of pizzas possible with the conditions below:
					   - Number of pizza slices must never exceed the number of participants
					   - Each pizza has a different number of slices.
	DATA FORM:			LINE1: <# OF PARTICIPANTS>	<TOTAL # OF PIZ_TYPES>
						LINE2: {SET OF ALL PIZZAS IN ASCENDING ORDER}
	EXPECTED OUTPUT: 	LINE1: <# OF PIZ_TYPES>
						LINE2: {SET OF SELECTED PIZZAS IN ASCENDING ORDER}
 ----------------------------------------------------------------------------------------------------------------------
	DATASETS INFORMATION:	SET	max_slices		TYPES
							a. 	17				4
							b. 	100				10
							c. 	4,500			50
							d. 	1,000,000,000	2,000
							e. 	505,000,000		10,000
 ----------------------------------------------------------------------------------------------------------------------
	ALGORITHM FORMULATION: A- INPUT				: OPEN INPUT FILE AND SCAN IN DATA
						   B- DATA PROCESSING	: SET PARAMETERS: MAX_PARTICIPANTS = MAX_SLICES	<--------- UPPER BOUND
												: MANIPULATE DATA: REORDER DATA TO DESCENDING ORDER
																   This is done by read and write data
																   simultaneously into an output file.
												: DETERMINE MAX_SLICES: This is done by adding data point by point
																		down the list.
																		Condition of termination: sum > max_slices
															Tuning sum: Open original input file
																		Read in data in ascending order
																		Add to <sum>
																		Condition of termination: sum > max_slices
						   C- OUTPUT			: OPEN OUTPUT FILE AND WRITE OUT RESULTS
														
			-----------------------------------------------------------------------------------------------------------
			UPDATE: 2020-02-17, MONDAY | 19:21
				B- DATA PROCESSING: REORGANIZING DATA IN DESCENDING ORDER
						This can be done by using array and pointer.
						First, read all raw data into arr1
						then, create pointers array ptr and points to arr1
						Finally, use for loop to arrange values of arr1 into new arr2
			UPDATE: 2020-02-17, MONDAY | 22:39
						NEED TO PUT ORIGINAL ASCENDING DATA INTO A SEPARATE FILE
						This is needed to fine tune <sum>.
			UPDATE: 2020-02-17, MONDAY | 23:18
				C- OUTPUT: PROBLEM! Needs to write data in the following format:
					   LINE1: <slices> <types>
					   LINE2: {set of selected types}
			UPDATE: 2020-02-18, TUESDAY | 08:05
				B- DATA PROCESSING: NEED TO USE GLOBAL ARRAYS, i.e. placed in main() to retain information,
						which is needed to write results into output file.
						Local function-bound arrays limit the options for later tasks.
			UPDATE: 2020-02-19, WEDNESDAY | 00:34
				B- DATA PROCESSING: CHANGED CODE TO UTILIZE GLOBAL ARRAYS. DONE AND WORKING LIKE A CHARM.
						NEW PROBLEM: How to push selected number into array3 of undeclared size.

***********************************************************************************************************************/

#include "Header.h"

int main(void)
{
	FILE* infile = NULL, * outfile = NULL;

	/******************************************************************************************************************
	PART A: INPUT --- OPENS INPUT FILE AND READ IN DATA
			also asks the user to enter the correct letter for corresponding dataset.
	*******************************************************************************************************************/
	char userchoice = '\0';

	while (userchoice == '\0')
	{
		userchoice = choose_dataset();
		if (userchoice == 'a')
			infile = fopen("a_example.in", "r");
		else if (userchoice == 'b')
			infile = fopen("b_small.in", "r");
		else if (userchoice == 'c')
			infile = fopen("c_medium.in", "r");
		else if (userchoice == 'd')
			infile = fopen("d_quite_big.in", "r");
		else if (userchoice == 'e')
			infile = fopen("e_also_big.in", "r");
		else
		{
			userchoice = '\0';
			printf("\nWRONG INPUT. PLEASE CHOOSE THE CORRECT DATASET.\n\n");
		}
	}
	
	/******************************************************************************************************************
	PART B: DATA PROCESSING
	*******************************************************************************************************************
			SETS PARAMETERS
	***************************************************************************/
	int max_slices = 0, max_types = 0, sum = 0;

	max_slices = read_data(infile);
	max_types = read_data(infile);

	int* arr1 = NULL, * arr2 = NULL, * arr3 = NULL;
	arr1 = malloc(sizeof(int) * max_types);
	arr2 = malloc(sizeof(int) * max_types);

	// PUSH DATA INTO ARRAY1 IN ASCENDING ORDER (LIKE ORIGINAL RAW)
	int i = 0, j = 0;
	for (i = 0; i < max_types; i++)
	{
		arr1[i] = read_data(infile);
		printf("[%d]:%d\t", i, arr1[i]);
	}

	// MIRROR DATA IN REVERSE ORDER INTO ARRAY2
	printf("\n\n");
	j = max_types - 1;
	for (i = 0; i < max_types; i++)
	{
		arr2[i] = arr1[j];
		j--;
		printf("[%d]:%d\t", i, arr2[i]);
	}

	printf("\n\n");
	for (i = 0; i < max_types; i++)
	{
		sum = sum + arr2[i];
		printf("[%d]	", sum);
		//arr3[i] = arr2[i];
		j++;
		if (sum > max_slices)
		{
			sum = sum - arr2[i];
			//arr3[i] = arr3[i + 1];
			j--;
			printf("[%d]	\n\n", sum);
			break;
		}
	}
	
	for (i = 0; i < max_types; i++)
	{
		sum = sum + arr1[i];
		printf("[%d]	", sum);
		//arr3[i] = arr2[i];
		j++;
		if (sum > max_slices)
		{
			sum = sum - arr1[i];
			//arr3[i] = arr3[i + 1];
			printf("[%d]----------[j, total selected = %d]", sum, j);
			break;
		}
	}
	
	/*arr3 = realloc(sizeof(int) * j);
	for (i = 0; i <= j; i++)
	{
		printf("%d ", arr3[i]);
	}*/

	//***************************************************************************
	//		FETCHES RAW DATA AND REORGANIZES
	//***************************************************************************/
	//outfile1 = fopen("rawdata.in", "w");
	//outfile2 = fopen("rawdata_new.in", "w");
	//if (userchoice == 'a')
	//{
	//	max_types = setAtypes;
	//	reorganize_dataset(infile, outfile1, outfile2, max_types);
	//}
	//else if (userchoice == 'b')
	//{
	//	max_types = setBtypes;
	//	reorganize_dataset(infile, outfile1, outfile2, max_types);
	//}
	//else if (userchoice == 'c')
	//{
	//	max_types = setCtypes;
	//	reorganize_dataset(infile, outfile1, outfile2, max_types);
	//}
	//else if (userchoice == 'd')
	//{
	//	max_types = setDtypes;
	//	reorganize_dataset(infile, outfile1, outfile2, max_types);
	//}
	//else if (userchoice == 'e')
	//{
	//	max_types = setEtypes;
	//	reorganize_dataset(infile, outfile1, outfile2, max_types);
	//}
	//fclose(outfile1);
	//fclose(outfile2);
	//**************************************************************************
	//		DETERMINES max_slices
	//***************************************************************************/
	//// OPENS RAWDATA.IN IN READ-MODE, READY FOR CALCULATION
	//FILE* newinfile = NULL, *newinfile2 = NULL;
	//newinfile = fopen("rawdata.in", "r");
	//newinfile2 = fopen("rawdata_new.in", "r");
	//int sum[2] = { 0,0 };
	//sum[1] = get_slices(newinfile, newinfile2, max_slices, max_types);
	// Push all values of <selected numbers> into a new array <arr3> and sort it
	// Write <sum> and <types> in output file.
	//int* arr3 = NULL;
	// size of arr3 is dictated by the selected <max_types>,
	// which is calculated in functinos.c
	// <arr3> must be initialized with 0 in all allocated blocks.
	// In order to do this, <sum> and <types> must be stored in main().
	// Write <arr3> in the output file.
	//fclose(newinfile);
	//fclose(newinfile2);
	//fclose(outfile1);
	//fclose(outfile2);
	
	fclose(infile);
	//fclose(outfile);
	return 0;
}
