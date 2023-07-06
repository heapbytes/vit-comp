#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void rot_cipher(char* inp, int shift, int size){

  char* rotstr = malloc(sizeof(char) * size);
  for(int i=0; i<size; i++){
    if(islower(inp[i])){
      rotstr[i] = ((int)inp[i] + shift - (int)'a') %26 + 'a';
    }else if(isupper(inp[i])){
      rotstr[i] = ((int)inp[i] + shift - (int)'A') %26 + 'A';
    }
    else{
      rotstr[i] = inp[i];
    }
  }

  for(int i=0; i<size; i++){
    printf("%c", rotstr[i]);
  }
  free(rotstr);
}

int main(){

  char* inp = NULL;
  size_t size = 0;
  int shift = 3;


  printf("Enter an input : ");
  if(getline(&inp, &size, stdin) != -1){
    rot_cipher(inp, shift, size);
  }else{
    printf("Error executing");
    return 1;
  }

  free(inp);
  return 0;
}

