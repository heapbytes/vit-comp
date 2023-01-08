#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *prev;
  int data;
  struct node *next;
};

void print_nodes(struct node *head){
  struct node *ptr = head;//malloc(sizeof(struct node));
  while(ptr!=NULL){
    printf("data = %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct node *delete_nodes(struct node *head){ 
  
  struct node *ptr = head;
  
  while(ptr->next != NULL){
    ptr = ptr->next;
    
    if(ptr->next = NULL){
      break;
    }
    //printf("\ndatax = %d", ptr->data); //(45) 
  }
  return head;
}

int main(){
  
  struct node *head = malloc(sizeof(struct node));
  head->prev = NULL;
  head->data = 45;
  head->next = malloc(sizeof(struct node));
  
  head->next->prev = head;
  head->next->data = 55;
  head->next->next = malloc(sizeof(struct node));

  head->next->next->prev = head->next;
  head->next->next->data = 65;
  head->next->next->next = NULL;

  printf("Printing data from nodes\n");
  print_nodes(head);
  
  printf("\nInserting data\n");
  insert_node(35);

  printf("\nNode after insertion of data\n");
  print_nodes(head);
  
  printf("\nNode after deletion of last node\n");
  delete_nodes(head);
  print_nodes(head);

  return 0;
}
