#include <stdio.h>
#include <string.h>

int main(){
  int arr[] = {1, 3, 33, 23, 26, 34};

  for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
    printf("%d\n", arr[i]);
  }
  return 0;

}


