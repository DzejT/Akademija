#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#define DELIM ";"

void parse_user_input(char *name, char *surname, char *email, char *number)
{
    printf("Enter name: ");
    fscanf(stdin, "%24s", name);

    printf("Enter surname: ");
    fscanf(stdin, "%24s", surname);

    printf("Enter email: ");
    fscanf(stdin, "%49s", email);

    printf("Enter number: ");
    fscanf(stdin, "%24s", number);
}

void parse_index(int *index){
    printf("Enter index: ");
    fscanf(stdin, "%d", index);
}

void parse_keyword(char *keyword){
    printf("Enter keyword: ");
    fscanf(stdin, "%49s", keyword);
}

int get_user_option()
{
    int c;
    printf("Enter your choice: ");
    fscanf(stdin, "%d", &c);
    while (getchar() != '\n' && c != EOF);
    return c;
}

void add_new_address(struct node **list)
{
    char name[25], surname[25], email[50], number[25];
    struct node *address = NULL;

    parse_user_input(name, surname, email, number);
    address = createNode(name, surname, email, number);
    if (address == NULL) {
        fprintf(stderr, "Unable to create new address\n");
        return;
    }
    add_to_list(list, address);
}

void add_address_at_index(struct node **list){
    int index;
    char name[25], surname[25], email[50], number[25];
    struct node *address = NULL;

    parse_index(&index);
    parse_user_input(name, surname, email, number);
    address = createNode(name, surname, email, number);

    if (address == NULL) {
        fprintf(stderr, "Unable to create new address\n");
        return;
    }
    add_to_list_at_index(list, address, index);

}

void find_at_position(struct node *list){
    int index;
    parse_index(&index);
    findByIndex(list, index);
}

void find_by_keyword(struct node *list){
    char keyword[50];
    parse_keyword(keyword);
    findByKey(list, keyword);
}

void delete_at_position(struct node **list){
    int index;
    parse_index(&index);
    delete(list, index);
}

void printHelp(){
    printf("1 - Display()\n");
    printf("2 - insertAtTheEnd()\n");
    printf("3 - insertByTheIndex()\n");
    printf("4 - findByIndex()\n");
    printf("5 - findByKey()\n");
    printf("6 - delete()\n");
    printf("7 - deleteAll()\n");
    printf("8 - exit()\n");
}

void parse_csv(struct node **head){
    FILE* f = fopen("Addresses.csv", "r");
    char name[25], surname[25], email[50], number[25];
    int a = 0;
    char line[120];

    while(fscanf(f, "%[^;];%[^;];%[^;];%[^;]", name, surname, email, number) == 4){
        fgets(line, sizeof(line), f); // čia nelabai gražiai taip atrodo, bet atrodo, kad fscanf() nepereina prie kitos eilutės, tai nelabai radau geresnių būdų
        add_to_list(head, createNode(name, surname, email, number));
    }
}

