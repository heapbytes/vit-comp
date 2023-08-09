#include <stdio.h>
#include <stdlib.h>


char* xor(char first[], char second[]){
  
  char* ans = (char*)malloc(sizeof(char) * 8);
  
  return ans;
}

void subnib(char* w){
  char* ques;
}

void rotnib(char* w){
  char* ans = malloc(sizeof(char) * 8);
  for(int i=0; i<8; i++){
    ans[i] = w[(i + 4) % 8];
  }
  w = ans;
}

int main(){
  
  char k1[] = "0100101011110101";
  char w0[8], w1[8];
  int size_k1 = sizeof(k1)/sizeof(k1[0]);

  for(int i=0; i<size_k1/2; i++){
    w0[i] = k1[i];
    w1[i+8] = k1[i+8];
  }

  //step 1
  //xor w0 with constant and xor subnib(rotnib(w1))
  char* constant_w2 = "10000000";
  char* w2 = xor(w0, constant_w2);
  w2 = xor(w2, subnib(rotnib(w1)));



  return 0;

}
