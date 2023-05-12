#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for(int i=0; i<=9;i++) {
        int counter = 0;
        for (int j = 0; j < strlen(s)+1; j++) {
            char tmp = i+'0';
            if(tmp == *(s+j))
                counter++;
        }
        printf("%d ", counter);
    }    
    return 0;
}
