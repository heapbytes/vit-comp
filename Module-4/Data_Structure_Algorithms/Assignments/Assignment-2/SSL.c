#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void print_nodes(struct node *head){
  if(head==NULL){
    printf("Node is empty");
    return;
  }
  struct node *ptr=head;
  while(ptr!=NULL){
    printf("data = %d\n", ptr->data);
    ptr = ptr->link;
  }
}

struct node *delete_nodes(struct node *head){
  if(head==NULL){
    printf("Node is empty");
  }
  struct node *ptr = head;
  struct node *prev_ptr = NULL;

  while(ptr->link != NULL){
    prev_ptr = ptr;
    ptr = ptr->link;
  }
  prev_ptr->link = NULL;
  return head;
  //you can also return prev_ptr since it is pointer which performs stuff on ptr, which results the changes in head as well..
}

int main(){

  struct node *head = malloc(sizeof(struct node));
  head->data = 45;
  head->link = malloc(sizeof(struct node));
  head->link->data = 55;
  head->link->link = malloc(sizeof(struct node));
  head->link->link->data = 65;
  head->link->link->link = NULL;

  printf("Printing data from nodes\n");
  print_nodes(head);
  
  printf("\nPrinting data after deleting the last node\n");
  delete_nodes(head);
  print_nodes(head);

  return 0;
}

