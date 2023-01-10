#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 6

char stack[MAX];
int top=-1;

int isFull();
int isEmpty();
void push(char);
int isOperator(char);
char pop();
int pre(char);

char infix[MAX],prefix[MAX],postfix[MAX],item,temp;
int i=0,j=0;

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


void push(char item){
	if(isFull()){
		printf("Stack overflow!\n");
	}else{
		top++;
		stack[top]=item;
	}
}

int isFull(){
	if(top==MAX-1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}

int isOperator(char symbol){
	if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^'){
		return 1;
	}else{
		return 0;
	}
}

char pop(){
	if(isEmpty()){
		return '\0';
	}
	char ch;
	ch=stack[top];
	top--;
	return ch;
}

int pre(char symbol){
	if(symbol=='^'){
		return 3;
	}else if(symbol=='*'||symbol=='/'){
		return 2;
	}else if(symbol=='+'||symbol=='-'){
		return 1;
	}else{
		return 0;
	}
}

void InToPre(char infix[MAX]){

    strrev(infix);

    while(infix[i]!='\0'){
		item=infix[i];
		if(item==')'){
			push(item);
		}else if(item>='A'&&item<='Z'||item>='a'&&item<='z'){
			prefix[j]=item;
			j++;
		}else if(isOperator(item)){
			temp=pop();
			while(isOperator(temp)==1&&pre(temp)>=pre(item)){
				prefix[j]=temp;
				j++;
				temp=pop();
			}
			push(temp);
			push(item);
		}else if(item=='('){
			temp=pop();
			while(temp!=')'){
				prefix[j]=temp;
				j++;
				temp=pop();
			}
		}else{
			printf("Invalid Arithmetix expression!\n");
			exit(0);
		}
		i++;
	}
	while(!isEmpty()){
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
	printf("\nThe prefix expression is:\t %s ",strrev(prefix));
}


int main(){
	
  char infix[] = "A+B*C";
	printf("\nInfix expression is:\t %s ", infix);
  InToPre(infix);
  return 0;
  }


