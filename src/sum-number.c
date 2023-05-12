#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a0, a1;
    float b0, b1;

	scanf("%d %d", &a0, &a1);
    scanf("%f %f", &b0, &b1);
    printf("%d %d\n", a0+a1, a0-a1);
    printf("%.1f %.1f", b0+b1, b0-b1);
    return 0;
}