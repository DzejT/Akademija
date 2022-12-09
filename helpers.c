#include <stdio.h>
#include "linkedlist.h"

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

void populateList(struct node **head){
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222220"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222221"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222222"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222223"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222224"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222225"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222226"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222227"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222228"));
    add_to_list(head, createNode("Jonas", "Jonauskas", "jonas@gmail.com", "862222229"));
}

