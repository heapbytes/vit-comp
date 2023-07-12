#include "des.h"

char* ip_on_p(char ip[], char p[]){
  
  char* ans = (char*)malloc(sizeof(char) * 8);
  for(int i=0; i<8; i++){
    ans[i] = p[ip[i] - '1']; // -1 because the indices starts from 0 and on paper I started from 1.
  }

  return ans;
}

char* divide_key(char* ans_ip, char ip[], int position){
  if(position == 0){
    char* ans = (char*)malloc(sizeof(char) * 4);
    for(int i=0; i<4; i++){
      ans[i] = ans_ip[i];
    }
    return ans;
  } 
  else if(position == 1){
    char* ans = (char*)malloc(sizeof(char) * 4);
    for(int i=4; i<8; i++){
      ans[i-4] = ans_ip[i];
    }
    return ans;
  }
  else{
    return "";
  }
}

char* apply_ep(char* ip_2, char ep[]){
  char* ans = (char*)malloc(sizeof(char) * 8);
  for(int i=0; i<8; i++){
    ans[i] = ip_2[ep[i] - '1'];
  }
  
  return ans;
}

char* xor(char* val1, char val2[]){

  char* ans = (char*)malloc(sizeof(char) * 9); //increasing by 1 because array is used, at last we have to add \0.
  for(int i=0; i<8; i++){
    ans[i] = val1[i] ^ val2[i];
  }
  
  ans[8] = '\0';
  return ans;
}

int main(){

  char k1[8] = "00101111";
  char k2[8] = "11101010";
  
  char p[8] = "10100101";    //plaintext
  char ip[8] = "26314857";   //initial permutation
  char ep[8] = "41232341";  //expantion permutation

  //step 1 : apply IP on P.
  char* ans_ip = ip_on_p(ip, p);
  //printf("%s\n", ans_ip);


  //step 2 : dividing above 8 bits ans_ip to 2x4 bits
  char* ip_1 = divide_key(ans_ip, ip, 0);
  char* ip_2 = divide_key(ans_ip, ip, 1);
  //printf("%s\n", ip_1);
  //printf("%s\n", ip_2);
  

  //step 3 : applying ep on ip_2
  char* ans_eip = apply_ep(ip_2, ep);
  //printf("%s\n", ans_eip);


  //step 4 : encrypting on ans_eip (using k1) [ xoring ans_eip and k1 ]
  char* enc_1 = xor(ans_eip, k1);
  printf("done enc\n");
  printf("%s\n", enc_1);


  


  return 0;
}
