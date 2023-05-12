#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int len =  2*n - 1;
    for(int i=0;i<len;i++) {
      for(int j=0;j<len;j++) {
          int min_row = i < len-i ? i: len-i-1;
          int min_col = j < len-j ? j: len-j-1;
          int min = min_col < min_row ? min_col: min_row;
          printf("%d ", n-min);
        }
      printf("\n");  
    }
    return 0;
}