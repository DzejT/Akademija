#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"
#define DELIM " "


int checkIndex(char *str){
    for (int i = 0; str[i] != '\0'; i++){
        if(!isdigit(str[i])){
            return -1;
        }
    }
    return 0;
}


int insertAtTheEnd(struct node** head, struct node** tail, char *str){
    char buffer[80];
    char* ptr;
    strcpy(buffer, str);
    struct node* link = (struct node*) malloc(sizeof(struct node));

    if(!(ptr = strtok(buffer, DELIM)))
        return 1;
    strcpy(link->firstname, ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->lastname, ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->email, ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->phone, ptr);

    if(strtok(NULL, DELIM) != NULL)
        return 1;

    link->next = NULL;
    if(*head == NULL){
        *head = link;
        *tail = link;
    }
    else{
        (*tail)->next = link;
        *tail = link;
    }
    return 0;
           
}

int insertByTheIndex(struct node** head, struct node** tail, char *str){
    char buffer[80];
    char* ptr;
    strcpy(buffer, str);
    struct node* link = (struct node*) malloc(sizeof(struct node));

    if(!(ptr = strtok(buffer, DELIM)))
        return 1;
    if(checkIndex(ptr) == -1)
        return 1;
    int index = atoi(ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->firstname, ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->lastname, ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->email, ptr);

    if(!(ptr = strtok(NULL, DELIM)))
        return 1;
    strcpy(link->phone, ptr);

    if(strtok(NULL, DELIM) != NULL)
        return 1;

    
    if(index == 0 || *head == NULL){
        link->next = *head;
        *head = link;
    }
    else{
        struct node* ptr = *head;
        int i = 1;
        while(i < index && ptr->next != NULL){
            ptr = ptr->next;
            i++;
        }
        if(ptr == *tail){
            (*tail)->next = link;
            *tail = link;
        }
        else{
            link->next = ptr->next;
            ptr->next = link;
        }      
    }
    return 0;
}

void display(struct node* head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%s %s %s %s\n", ptr->firstname, ptr->lastname, ptr->email, ptr->phone);
        ptr = ptr->next;
    }
}

void findByKey(struct node* head, char *key) {

    struct node* ptr = head;

    while(ptr != NULL) {	
        if((strcmp(ptr->firstname, key) == 0) || (strcmp(ptr->lastname, key) == 0) || (strcmp(ptr->email, key) == 0) || (strcmp(ptr->phone, key) == 0)){
            printf("%s %s %s %s\n", ptr->firstname, ptr->lastname, ptr->email, ptr->phone);
            return;
        }

        ptr = ptr->next;
    }
    printf("Element was not found\n");
}

void findByIndex(struct node* head, int index) {

    struct node* ptr = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i <= index; i++){
        if(index == i){
            printf("%s %s %s %s\n", ptr->firstname, ptr->lastname, ptr->email, ptr->phone);
            return;
        }
        if(ptr->next == NULL)
            break;
        ptr = ptr->next;
    }

    printf("Element was not found\n");
    return;
}

void delete(struct node** head, struct node** tail, int index){
    struct node* temp;
    if(index == 0){
        temp = *head;
        *head = (*head)->next;
    }
    else{
        int i = 1;
        struct node* ptr = *head;
        while(i < index && ptr->next != NULL){
            i++;
            ptr = ptr->next;
        }
        if(ptr->next == NULL){
            fprintf(stderr,"Invalid index\n");
            return;
        }
        temp = ptr->next;
        if(ptr->next == *tail){
            printf("tail\n");
            ptr->next == NULL;
            *tail = ptr;
        }
        else{
            ptr->next = ptr->next->next;
        }
    }
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