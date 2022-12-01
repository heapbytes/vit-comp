#include <stdio.h>
#include <string.h>

/*
-->Problem Statement: 
WAP to implement Insertion sort and Quick Sort on 1D array of Student
structure (contains student_name, student_roll_no, total_marks), with
key as student_roll_no. And count the number of swap performed.
*/

struct data{
  int roll;
  float total;
  char name[10];
};

void quicksort(){
  
}


int main(){
  
  struct data s1[10];
  int count;

  printf("Enter the no. : ");
  scanf("%d", &count);
  
  for(int i=0; i<count;i++){
    
    printf("Enter name: ");
    scanf("%s", s1[i].name);

    printf("Enter roll number: ");
    scanf("%d", &s1[i].roll);

    printf("Enter total marks: ");
    scanf("%f", &s1[i].total);
  }

  for(int i=0; i<count; i++){
    printf("\nName: %s \n", s1[i].name);
    printf("Roll number : %d \n", s1[i].roll);
    printf("total marks : %f\n", s1[i].total);
  }
   
  return 0;
}


