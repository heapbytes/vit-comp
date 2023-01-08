#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *prev;
  int data;
  struct node *next;
};


struct node *insert_node(struct node *head, int data){
  struct node *ptr = head;
  struct node *prev_n = ptr;
  
  while(ptr->next != NULL){
    prev_n = ptr;
    ptr = ptr->next;
  }

  struct node *new = malloc(sizeof(struct node));
  new->prev = prev_n;
  new->data = data;
  new->next = NULL;

  //adding the new node into the current links....
  ptr->next = new;
  new->prev = ptr;

  return head;
}

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
    //printf("\ndatax = %d", ptr->data); //(45) 
  }
  if(ptr->next == NULL){
    ptr->prev->next = NULL;    
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
  
  insert_node(head, 75);
  insert_node(head, 85);

  printf("\nNode after insertion of data\n");
  print_nodes(head);
  
  printf("\nNode after deletion of last node\n");
  delete_nodes(head);
  print_nodes(head);

  return 0;
}
