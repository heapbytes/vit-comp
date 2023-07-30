#ifndef CIPHER_H
#define CIPHER_H

//libraries
#include <stdio.h>
#include <stdlib.h>

//functions

//des_key_create.c
void leftshift(int arr[], int size, int shift);
int* get_key(int arr[], int arr2[]);
void apply_p10(int k, int k_1[], int k_2[]);

//encryption.c
char* ip_on_p(char ip[], char p[]);
char* divide_key(char* ans_ip, char ip[], int position);
char* apply_ep(char* ip_2, char ep[]);
char* get_bin(char s0[], char s1[], char* enc);

#endif

