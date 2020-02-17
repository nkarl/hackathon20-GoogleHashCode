#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define setAmax 17
#define setBmax 100
#define setCmax 4500


char choose_dataset(void);

int read_data(FILE* infile);

void reorganize_data(FILE* infile, FILE* outfile, int counter);