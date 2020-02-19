#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define setAtypes 4
#define setBtypes 10
#define setCtypes 50
#define setDtypes 2000
#define setEtypes 10000

// ASKS USER TO CHOOSE ONE LETTER CORRESPONDING TO A DATA-SET.
char choose_dataset(void);

// READS ONE DATA-POINT FROM INPUT FILE WHEN INVOKED. MEANT TO BE RECYCLED IN LOOPS.
int read_data(FILE* infile);