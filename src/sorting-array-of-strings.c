#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) 
{
    // sort the strings in lexicographically non-decreasing order
    // return (*a < *b)?0:1;
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    //  sort the strings in lexicographically non-increasing order.
    // return (*a > *b)?0:1;
    return -strcmp(a,b);
}

int count_unique_char(const char* a) 
{
    int hash[128] = {0};
    int i, c = 0;

    for (i =0; i< strlen(a); i++) {
        hash[a[i]] = 1;
    }

    for (i=0;i<128;i++) {
        c += hash[i];
    }

    return c;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    // sort the strings in non-decreasing order of the number of distinct characters present in them
    // if two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first.
    if (count_unique_char(a) < count_unique_char(b))
        return -1;
    else if (count_unique_char(a) > count_unique_char(b))
        return 1;
    else return lexicographic_sort(a, b);
}

int sort_by_length(const char *a, const char *b) 
{
    // sort the strings in non-decreasing order of their lengths
    // if two strings have the same length, then the lexicographically smaller string should appear first.
    if (strlen(a) < strlen(b))
        return -1;
    else if (strlen(a) > strlen(b))
        return 1;
    else 
        return lexicographic_sort(a, b);
}

void swap(char **a, char **b) 
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;     
}


void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    int i,j;

    for(i = 0; i < len - 1; i++) {
        for(j = 0; j < len - i -1; j++) {
            // printf("%d", cmp_func(arr[j], arr[j + 1]));
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    } 
}

int main()
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    // printf("%d\n", sort_by_length(arr[0], arr[1]));
    // printf("%d %d", count_unique_char(arr[0]), count_unique_char(arr[1]));
    // printf("%d", sort_by_number_of_distinct_characters(arr[0], arr[1]));

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
    
    return 0;
}