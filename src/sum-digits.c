#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum_of_digits;
    for (int i = 0; i < 5; i++) {
        sum_of_digits += n%10;
        n = n/10;
    }
    printf("%d", sum_of_digits);
    return 0;
}