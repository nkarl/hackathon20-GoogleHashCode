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
			REORGANIZES DATA USING ARRAY
	***************************************************************************/

	outfile = fopen("rawdata.in", "w");
	int counter = 0;
	while (infile != NULL)
	{
		if (userchoice == 'a')
		{
			counter = setAmax;
			
		}
		else if (userchoice == 'b')
			;
		else if (userchoice == 'c')
			;
	}
	return 0;
}