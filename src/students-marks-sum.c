#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int sum = 0;
  // if (number_of_students == 1 && gender == 'b') 
  //   return *(marks);

  // if (number_of_students == 1 && gender == 'g') 
  //   return 0;

  // if(gender == 'b') {
  //   if ((number_of_students-1)%2 == 0)
  //       return *(marks + (number_of_students-1)) + marks_summation(marks, number_of_students-3, gender);
  //   else
  //       return *(marks + (number_of_students-2)) + marks_summation(marks, number_of_students-4, gender);
  // }
  // if(gender == 'g') {
  //   if ((number_of_students-1)%2 == 1)
  //       return *(marks + (number_of_students-1)) + marks_summation(marks, number_of_students-3, gender);
  //   else
  //       return *(marks + (number_of_students-2)) + marks_summation(marks, number_of_students-4, gender);
  // }
  for(int i = (gender=='b'?0:1); i<number_of_students;i=i+2) {
    sum += *(marks+i);
  }
  return sum;
} 

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}