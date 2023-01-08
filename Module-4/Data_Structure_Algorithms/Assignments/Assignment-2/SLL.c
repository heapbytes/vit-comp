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

struct node *add_node(struct node *head, int data){
  
  struct node *ptr = head;
  while(ptr->link !=NULL){
    ptr = ptr->link;
  }
  ptr->link = malloc(sizeof(struct node));
  ptr->link->data = data;  
  ptr->link->link = NULL;

  return head;
  //if you are too tired to return things use void to declare the functions, the updates will still reflect since we are playing with pointers :) 
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
  head->link = NULL;
  /*head->link = malloc(sizeof(struct node));
  head->link->data = 55;
  head->link->link = malloc(sizeof(struct node));
  head->link->link->data = 65;
  head->link->link->link = NULL; */

  printf("Printing data from nodes\n");
  print_nodes(head);
  
  printf("\nInserting data\n");
  add_node(head, 75);
  add_node(head, 85);
  add_node(head, 95);
  print_nodes(head);

  printf("\nPrinting data after deleting the last node\n");
  delete_nodes(head);
  print_nodes(head);

  return 0;
}

