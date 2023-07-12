#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

void railfence(char* inp, int size, int tracks){

  char railarr[size][tracks];
  for(int i=0; i<tracks; i++){
    for(int j=i; j<size; j++){
      railarr[i][j] = '\0';
    }
  }

  int record = 1;
  int flag = 0;

  for(int i=0; i<size; i++){
    if(record == 2 || flag==1){
      railarr[i][record] = inp[i];
      record--;
      flag = 1;
    }else if(record == 0){
      flag = 0;
    }
    if(flag == 0){
    railarr[i][record] = inp[i];
    record++;
    }
  }

  char* cipher = malloc(sizeof(char) * size);
  for(int i=0; i<tracks; i++){
    for(int j=0; j<size; j++){
      if(railarr[i][j] != '\0'){
        cipher[j] = railarr[i][j];
        printf("%c", railarr[i][j]);
      }
    }
  }


}

int main(){

  char* inp = malloc(sizeof(char) * 100);
  size_t size = 0;
  int rail_no = 3;

  printf("Enter a string : ");
  if(getline(&inp, &size, stdin) != -1){
    railfence(inp, strlen(inp), rail_no);
  }else{
    printf("Error on execution\n");
    return 1;
  }




  return 0;
}
