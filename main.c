#include <stdlib.h>
#include <stdio.h>
#include "r_ppois.h"

 
 
 
 
 
int main()
{
  char *argv[] = {"r_ppois", "--quiet"};
  int argc = 2;
  double *result;
  double q;
  double lambda;
  //printf("Enter the Q value (Number of Success): ");
  //scanf("%lf",&q);
  //printf("Enter the lambda value ");
  //scanf("%lf",&lambda);
  
  
  
  result = r_ppois(16,12);
  printf("\nInside main %lf",*result);
   
  return 0;
}
