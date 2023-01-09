#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

//void count_heads(struct node *head){ //this is another way of writing parameters
void count_heads(void *head){
  int count=0;
  if(head == NULL){
    printf("Node is empty\n");
    return;
  }
  struct node *ptr=head;
  while(ptr!=NULL){
    count++;
    ptr = ptr->link;
  }
  printf("Total count is : %d\n", count);
}

int main(){
  
  struct node *head=NULL;
  head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node *head2 = malloc(sizeof(struct node));
  head2->data = 55;
  head2->link = NULL;

  struct node *head3 = malloc(sizeof(struct node));
  head3->data = 65;
  head3->link = NULL;
  
  //now connecting previous nodes
  head->link = head2;
  head2->link = head3;

  count_heads(head);

  return 0;
}

