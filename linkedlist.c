#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"
#define DELIM " "


struct node* createNode(char *name, char *surname, char *email, char *number)
{
    struct node* link = (struct node*) malloc(sizeof(struct node));
    if(link == NULL){
        return NULL;
    }
    strcpy(link->firstname, name);
    strcpy(link->lastname, surname);
    strcpy(link->email, email);
    strcpy(link->phone, number);
    link->next = NULL;
    return link;
}

void add_to_list(struct node **list, struct node *address)
{
    struct node *temp = *list;
    if(*list == NULL) {
        *list = address; 
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = address;
}

void add_to_list_at_index(struct node **list, struct node *address, int index){
    if(index == 1 || *list == NULL){
        address->next = *list;
        *list = address;
    }
    else{
        struct node* ptr = *list;
        int i = 1;
        while(i < index-1){
            if(ptr == NULL){
                fprintf(stderr,"index is out of range\n");
                return;
            }
            ptr = ptr->next;
            i++;
        }
       
        address->next = ptr->next;
        ptr->next = address;   
    }
}

void display(struct node* head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct node* ptr = head;
    while(ptr != NULL){
        print_node(ptr);
        ptr = ptr->next;
    }
}

void print_node(struct node *address)
{
    if(address == NULL) {
        return;
    }
    printf("%s %s %s %s\n", address->firstname, address->lastname, address->email, address->phone);
}


void findByKey(struct node* head, char *key) {

    struct node* ptr = head;
    int i = 0;

    while(ptr != NULL) {	
        if((strcmp(ptr->firstname, key) == 0) || (strcmp(ptr->lastname, key) == 0) || (strcmp(ptr->email, key) == 0) || (strcmp(ptr->phone, key) == 0)){
            print_node(ptr);
            i++;
        }
        ptr = ptr->next;
    }
    if( i == 0) {
        printf("Element was not found\n");
    }
    
}



//nežinau ar šitoj funkcijoj geriau tiesiog išspausdinti tą node'a ar grąžinti ir kitoj vietoj su juo kažką daryti. Tas pats ir findByKey() funkcijoje
void findByIndex(struct node* head, int index) {

    struct node* ptr = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    for(int i = 1; i <= index; i++){
        if(index == i){
            print_node(ptr);
            return;
        }
        if(ptr->next == NULL)
            break;
        ptr = ptr->next;
    }

    printf("Element was not found\n");
    return;
}

void delete(struct node** head, int index){
    struct node* ptr = *head;
    struct node* temp;

    if(index == 1){
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return; 
    }

    int i = 2;
    while(i < index && ptr->next != NULL){
        i++;
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        fprintf(stderr,"Invalid index\n");
        return;
    }
    
    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
    
}

void deleteAll(struct node** head){
    struct node* tmp;
    while (*head != NULL)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}
