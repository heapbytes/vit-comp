//standard libraries are included in the following header file.
#include "des.h"

void leftshift(int arr[], int size, int shift){

  int* shiftedarr = malloc(sizeof(int) * size);
  int first = (shift < size) ? (shift % size) : ((shift - size) % shift);

  for(int i=0; i<size; i++){
    shiftedarr[i] = arr[(first + i) % size];
    //printf("%d ", shiftedarr[i]);
  }

  for(int i=0; i<size; i++){
    arr[i] = shiftedarr[i];
  }

  free(shiftedarr);  
}


int* get_key(int arr[], int arr2[]){
  int p8[] = {6, 3, 7, 4, 8, 5, 10, 9};

  int* key = malloc(sizeof(int) * 8);
  int size_ = 5;

  for(int i=0; i<8; i++){
    if (p8[i] <= size_) {
      key[i] = arr[p8[i]-1];
    } else {
      key[i] = arr2[p8[i] - size_ - 1];
    }
  }

  return key;
}


void apply_p10(int k, int k_1[], int k_2[]) {
  int p10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
  int k_[10];
  for (int i = 9; i >= 0; i--) {
    int val_k = k % 10;
    k_[i] = val_k;
    k /= 10;
  }

  for (int i = 0; i < 5; i++) {
    k_1[i] = k_[p10[i] - 1];
  }

  for (int i = 5; i < 10; i++) {
    k_2[i - 5] = k_[p10[i] - 1];
  }
}

int main(){


  int k; //0010010111
  printf("enter the value of k (without spaces) : ");
  scanf("%d", &k);

  int k_1[5];
  int k_2[5];

  /* APPLYING p10 */
  //int p10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
  apply_p10(k, k_1, k_2);

  //applying left shift by 1
  leftshift(k_1, sizeof(k_1) / sizeof(k_1[0]) ,1);
  leftshift(k_2, sizeof(k_2) / sizeof(k_2[0]) ,1);

  //Getting value of key1
  //int p8[] = {6, 3, 7, 4, 8, 5, 10, 9};
  int* key1 = get_key(k_1, k_2);


  /* GETTING VALUE k2 */

  //applying left shift by 2 on prev left shift 1 output.
  leftshift(k_1, sizeof(k_1) / sizeof(k_1[0]) ,2);
  leftshift(k_2, sizeof(k_2) / sizeof(k_2[0]) ,2);

  //value of k2
  //int p8[] = {6, 3, 7, 4, 8, 5, 10, 9};
  int* key2 = get_key(k_1, k_2);


  /* PRINTING VALUES */
  printf("\nValue of k1 : ");
  for(int i=0; i<8; i++){
    printf("%d", key1[i]);
  }

  printf("\nValue of k2 : ");
  for(int i=0; i<8; i++){
    printf("%d", key2[i]);
  }

  free(key1);
  free(key2);

  printf("\n");
  return 0;

}
