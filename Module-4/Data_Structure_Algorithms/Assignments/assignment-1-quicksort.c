//WAP to implement Bucket Sort and Quick sort on 1D array of Faculty
//structure (contains faculty_name, faculty_ID, subject_codes,
//class_names), with key as faculty_ID. And count the number of swap
//performed

#include <stdio.h>
#include <string.h>

struct facultyy {
  char faculty_name[50];
  int faculty_subject_code;
  int faculty_ID;
};

typedef struct facultyy Faculty;
Faculty fac[10];
int count = 0;

void swap(Faculty *a, Faculty *b) {
  Faculty t;
  t = *a;
  *a = *b;
  *b = t;
  count++;
}

int partition(Faculty fac[], int low, int high) {
  int pivot = low;
  int i = low + 1;
  int j = high;
  int tfac;

  do{
    while(fac[i].faculty_ID <= fac[pivot].faculty_ID && i<high) {
      i++;
    }
    while(fac[j].faculty_ID > fac[pivot].faculty_ID) {
      j--;
    }
    if(i < j) {
      swap(&fac[i], &fac[j]);
    }
  } while(i < j);

  swap(&fac[pivot], &fac[j]);
  return j;
}

void quickSort(Faculty fac[], int low, int high) {
  int partitionIndex;
  if(low < high) {
    partitionIndex = partition(fac, low, high);
    quickSort(fac, low, partitionIndex - 1);
    quickSort(fac, partitionIndex + 1, high);
  }
}


int main() {
  int n, B[10];
  printf("Enter the total no. of faculty: ");
  scanf("%d", &n);
  printf("\n");
  for(int i = 0; i < n; i++) {
    printf("Faculty Name: ");
    scanf("%s", fac[i].faculty_name);
    printf("Faculty subject_code: ");
    scanf("%d", &fac[i].faculty_subject_code);
    printf("Faculty No.: ");
    scanf("%d", &fac[i].faculty_ID);
    printf("\n");
  }
  quickSort(fac, 0, n-1);
  printf("\nSorting using Quick Sort: ");
  for(int i = 0; i < n; i++) {
    printf("\nFaculty No.: %d", fac[i].faculty_ID);
    printf("\nFaculty Name: %s", fac[i].faculty_name);
    printf("\nFaculty subject_code: %d", fac[i].faculty_subject_code);
    printf("\n");
  }
  printf("\nSwap count : %d\n", count);
  return 0;
}
