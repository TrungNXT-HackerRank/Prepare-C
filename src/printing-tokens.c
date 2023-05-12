#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// int main() 
// {

    // char *s;
    // s = malloc(1024 * sizeof(char));
    // scanf("%[^\n]", s);
    // s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    // *(s+strlen(s)+1)='\n';

    // for(char* c=s; *c != '\n'; c++) {
    //     if(*c == ' ') {
    //         *c = '\n';
    //     }
    // }
    // printf("%s", s);
    // return 0;
// }

#include <stdio.h>
#include <string.h>

char * getWord(const char *s, size_t n)
{
    while ( ( s += strspn(s, " \t") ) != NULL && n-- )
    {
        s += strcspn(s, " \t");
    }
    return *s ? (char *)s : (char *)0;
}

int main( void )
{
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    size_t n = 0;

    for (char *p; (p = getWord(s, n)) != NULL; ++n)
    {
        size_t len = strcspn(p, " \t");
        printf("%*.*s\n", ( int )len, ( int )len, p);
    }
   
    return 0;
}