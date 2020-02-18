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
							a.	17					4
							b.	100					10
							c.	4,500				50
							d. 1,000,000,000		2,000
							e. 505,000,000			10,000
 ----------------------------------------------------------------------------------------------------------------------
	ALGORITHM FORMULATION: A- INPUT				: OPEN INPUT FILE AND SCAN IN DATA
											
						   B- DATA PROCESSING	: SET PARAMETERS: MAX_PARTICIPANTS = MAX_SLICES		<----- UPPER BOUND

												: MANIPULATE DATA: REORDER DATA TO DESCENDING ORDER
																   This is done by read and write data
																   simultaneously into an output file.

												: DETERMINE MAX_SLICES: This is done by adding data point by point
																		down the list.

																		Condition of termination: sum > max
																		Tuning sum: open original input file
																					read in data in ascending order
																					add to <sum>
																		Condition of termination: sum > max

						   C- OUTPUT			: OPEN OUTPUT FILE AND WRITE OUT RESULTS
						   --------------------------------------------------------------------------------------------
					UPDATE: 2020-02-17, MONDAY | 19:21
							B- DATA PROCESSING: REORGANIZING DATA IN DESCENDING ORDER
												This can be done by using array and pointer.
												First, read all raw data into arr1
												then, create pointers array ptr and points to arr1
												Finally, use for loop to arrange values of arr1 into new arr2

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

	max = read_data(infile);
	num_types = read_data(infile);

	/**************************************************************************
			FETCHES RAW DATA AND REORGANIZES
	***************************************************************************/

	outfile = fopen("rawdata.in", "w");
	
	int counter = 0;
	
	if (userchoice == 'a')
	{
		counter = setAtypes;
		reorganize_datasetA(infile, outfile, counter);
	}

	else if (userchoice == 'b')
	{
		counter = setBtypes;
		reorganize_datasetA(infile, outfile, counter);
	}
	else if (userchoice == 'c')
	{
		counter = setCtypes;
		reorganize_datasetA(infile, outfile, counter);
	}
	

	fclose(infile);
	fclose(outfile);
	return 0;
}