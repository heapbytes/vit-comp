#include <stdio.h>

struct faculty {
  char faculty_name[10];
  int faculty_ID;
  int faculty_subj_code;
};

typedef struct faculty Faculty;
Faculty fac[5];
int count = 0;

void swap(Faculty *a, Faculty *b)
{
  Faculty temp;
  temp = *a;
  *a = *b;
  *b = temp;

  count++;
}
void key_value(Faculty fac[], int N, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < N && (fac[left].faculty_ID > fac[largest].faculty_ID))
    largest = left;
  if (right < N && (fac[right].faculty_ID > fac[largest].faculty_ID))
    largest = right;
  if (largest != i) {
    swap(&fac[i], &fac[largest]);
    key_value(fac, N, largest);
  }
}
void heapSort(Faculty fac[], int N)
{
  for (int i = N / 2 - 1; i >= 0; i--)
    key_value(fac, N, i);
  for (int i = N - 1; i >= 0; i--) {
    swap(&fac[0], &fac[i]);
    key_value(fac, i, 0);
  }
}

int main()
{
  int N;
  printf("Enter the total no. of factultys: ");
  scanf("%d",&N);
  printf("\n\n");
  for(int i=0; i<N; i++) {
    printf("Name: ");
    scanf("%s",fac[i].faculty_name);
    printf("Faculty No.: ");
    scanf("%d",&fac[i].faculty_ID);
    printf("Faculty Subject code: ");
    scanf("%d",&fac[i].faculty_subj_code);
    printf("\n");
  }
  heapSort(fac, N);
  printf("\nSorting using Heap Sort: ");
  for(int i=0;i<N;i++) {
    printf("\nFaculty No.: %d",fac[i].faculty_ID);
    printf("\nName: %s",fac[i].faculty_name);
    printf("\nFaculty Subject code: %d",fac[i].faculty_subj_code);
    printf("\n");
  }
  printf("\nSwap count: %d\n",count);

  return 0;
}
