/**********************************************************************************************************************
	PROJECT: GOOGLE HASHCODE | JUDGE SYSTEM
	TEAM: COUGARS RAWR: 3	--- MEMBERS: KARL-ALBERT
										 ROGUE_RUSSIAN
										 WENZHI ZHUANG
	PROBLEM STATEMENT: Order the maximum number of pizzas possible with the conditions below:
					   - Number of pizza slices must never exceed the number of participants
					   - Each pizza has a different number of slices.
	DATA FORM:		 LINE1: <# OF PARTICIPANTS>		<TOTAL # OF PIZ_TYPES>
					 LINE2: {SET OF ALL PIZZAS IN ASCENDING ORDER}
	EXPECTED OUTPUT: LINE1: <# OF PIZ_TYPES>
					 LINE2: {SET OF SELECTED PIZZAS IN ASCENDING ORDER}
 ----------------------------------------------------------------------------------------------------------------------
	DATASETS INFORMATION:	SET	MAX					TYPES
							a. 17					4
							b. 100					10
							c. 4,500				50
							d. 1,000,000,000		2,000
							e. 505,000,000			10,000
 ----------------------------------------------------------------------------------------------------------------------
	ALGORITHM FORMULATION: A- INPUT				: OPEN INPUT FILE AND SCAN IN DATA
						   B- DATA PROCESSING	: SET PARAMETERS: MAX_PARTICIPANTS = MAX_SLICES	<--------- UPPER BOUND
												: MANIPULATE DATA: REORDER DATA TO DESCENDING ORDER
																   This is done by read and write data
																   simultaneously into an output file.
												: DETERMINE MAX_SLICES: This is done by adding data point by point
																		down the list.
																		Condition of termination: sum > max
															Tuning sum: Open original input file
																		Read in data in ascending order
																		Add to <sum>
																		Condition of termination: sum > max
						   C- OUTPUT			: OPEN OUTPUT FILE AND WRITE OUT RESULTS
														
						   --------------------------------------------------------------------------------------------
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
***********************************************************************************************************************/

#include "Header.h"

int main(void)
{
	FILE* infile1 = NULL, * outfile1 = NULL, * outfile2 = NULL;

	/******************************************************************************************************************
	PART A: INPUT --- OPENS INPUT FILE AND READ IN DATA
			also asks the user to enter the correct letter for corresponding dataset.
	*******************************************************************************************************************/
	char userchoice = '\0';

	while (userchoice == '\0')
	{
		userchoice = choose_dataset();
		if (userchoice == 'a')
			infile1 = fopen("a_example.in", "r");
		else if (userchoice == 'b')
			infile1 = fopen("b_small.in", "r");
		else if (userchoice == 'c')
			infile1 = fopen("c_medium.in", "r");
		else if (userchoice == 'd')
			infile1 = fopen("d_quite_big.in", "r");
		else if (userchoice == 'e')
			infile1 = fopen("e_also_big.in", "r");
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
	int max = 0, num_types = 0, num_slices = 0;

	max = read_data(infile1);
	num_types = read_data(infile1);

	/**************************************************************************
			FETCHES RAW DATA AND REORGANIZES
	***************************************************************************/
	outfile1 = fopen("rawdata.in", "w");
	outfile2 = fopen("rawdata_new.in", "w");
	
	if (userchoice == 'a')
	{
		num_types = setAtypes;
		reorganize_dataset(infile1, outfile1, outfile2, num_types);
	}

	else if (userchoice == 'b')
	{
		num_types = setBtypes;
		reorganize_dataset(infile1, outfile1, outfile2, num_types);
	}
	else if (userchoice == 'c')
	{
		num_types = setCtypes;
		reorganize_dataset(infile1, outfile1, outfile2, num_types);
	}

	else if (userchoice == 'd')
	{
		num_types = setDtypes;
		reorganize_dataset(infile1, outfile1, outfile2, num_types);
	}

	else if (userchoice == 'e')
	{
		num_types = setEtypes;
		reorganize_dataset(infile1, outfile1, outfile2, num_types);
	}
	
	fclose(outfile1);
	fclose(outfile2);
	/**************************************************************************
			DETERMINES MAX_SLICES
	***************************************************************************/
	// OPENS RAWDATA.IN IN READ-MODE, READY FOR CALCULATION
	FILE* newinfile1 = NULL, *newinfile2 = NULL;
	newinfile1 = fopen("rawdata.in", "r");
	newinfile2 = fopen("rawdata_new.in", "r");

	int sum[2] = { 0,0 };
	sum[1] = get_slices(newinfile1, newinfile2, max, num_types);
	
	fclose(newinfile1);
	fclose(newinfile2);
	fclose(outfile1);
	fclose(outfile2);
	return 0;
}
