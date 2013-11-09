#include"stdio.h"

/*
* problem: we have matrix[5][5], values are unsorted 0-24. special is 0, it can swap with its upper,lower,left,right num which is named as U/D/L/R  
* input: source mat[5][5] and result mat[5][5]. and a sequence of the movement. output: the movement sequence in correct order; if not, output "None"
*/
const int MaxN = 5;
void findZeroMove(int[5][5], int[5][5], char* seq, int length);
void sort(char[], int length);
