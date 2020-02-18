#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define setAtypes 4
#define setBtypes 10
#define setCtypes 50


char choose_dataset(void);

int read_data(FILE* infile);

void reorganize_datasetA(FILE* infile, FILE* outfile, int counter);