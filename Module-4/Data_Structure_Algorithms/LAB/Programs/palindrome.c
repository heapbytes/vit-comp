#include <stdio.h>
#include <string.h>

int main(){
  
  printf("Start\n");
  char s1[] = "sopop";
  char s2[] = "pophos";
  int i, num=0;

  if(strlen(s1)==strlen(s2)){
    for(i=strlen(s1); i>0; i--){
      if(s1[i] == s2[num]){
       // printf("+1 at %s", s1[i]);
        num++;
      }
    } 
  } 
  strcat(s2, '\0');
  printf("The length is %d\n", num);
  if(num == strlen(s1)){
    printf("palindrome\n");
  }
  else{
    printf("no sry\n");
  }

  return 0;
}

