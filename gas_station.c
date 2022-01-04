/**
 * Gas station problem: On a ring road there are N station. Each station has
 * certain quantity of gas listed in array A. Array B denotes the amount of gas
 * needed to go to next station 0, 1, 2, 3, ... N, 0, 1. 
 * Find the first station where the car can start and complete one full circle. 
 *
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */
//int canCompleteCircuit(const int* A, int n1, const int* B, int n2) {
#include <stdio.h>
int main ()
{    
 // int A[2]={1, 2};
 //	int B[2]={2, 1};
  int A[4]={1, 1, 3, 4};
	int B[4]={2, 2, 1, 3};
	int n1 = 2;
	int fit = 0; // fit: fuel in tank
  int ssf = 1; // ssf: success so far
  int i;
  int j;

  for (i = 0; i < n1; i++) {
    fit = 0;
    ssf = 1;
    for (j = i; j < n1; j++) {
      fit = fit + A[j];    // add fuel available at stn
      fit = fit - B[j];    // substract fuel needed for next stn
      if (fit < 0) {
        ssf = 0;
        printf("Fuel in tank goes negative at %d when started at %d\n", j, i);
				break;
      }
    }
    if (ssf) {
      for(j = 0; j < i; j++) {
        fit = fit + A[j];    
        fit = fit - B[j];                            
        if (fit < 0) {
          ssf = 0;    // ssf: success so far is set to false
          printf("Fuel in tank goes negative at %d when started at %d\n", j, i);
          break;
        }
      }
    }
    if (ssf){
			printf("Station %d\n", i);
			return(i);   
  	}
  }
}
