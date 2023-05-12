#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double square_of_area(triangle tri)
{
    return (tri.a + tri.b + tri.c) * (tri.a + tri.b - tri.c) * (tri.a + tri.c - tri.b) * (tri.b + tri.c - tri.a);
}
    
void assign_triangle(triangle* first, triangle* last)
{
    first->a = last->a;
    first->b = last->b;
    first->c = last->c;
} 
    
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    for( int i = 1; i < n; i++) {
        triangle last;
        assign_triangle(&last, &tr[i]);
        int j = i;
        while(j > 0 && (square_of_area(tr[j-1]) >= square_of_area(last))) {
            assign_triangle(&tr[j], &tr[j-1]);
            j--;
        }
        assign_triangle(&tr[j], &last);
    }    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}