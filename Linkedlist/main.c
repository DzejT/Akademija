#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"


struct node *head = NULL;
struct node *tail = NULL;


void printHelp();
void populateList();

int main()
{    
    populateList();
    printHelp();

    char choice[3];
    while(fgets(choice, sizeof(choice), stdin) != NULL)
    {
        size_t ln;
        char buffer[80];
        switch(atoi(choice)){
            case 1:
                display(head);
                break;
            case 2:
                printf("enter firstname lastname email and phone number\n");
                fgets(buffer, sizeof(buffer), stdin);
                ln = strlen(buffer) - 1;
                if (buffer[ln] == '\n')
                    buffer[ln] = '\0';
                if(insertAtTheEnd(&head, &tail, buffer) != 0)
                    printf("Input data was incorrect\n");
                break;
            case 3:
                printf("enter index firstname lastname email and phone number\n");
                fgets(buffer, sizeof(buffer), stdin);
                ln = strlen(buffer) - 1;
                if (buffer[ln] == '\n')
                    buffer[ln] = '\0';
                if(insertByTheIndex(&head, &tail, buffer) != 0){
                    printf("Input data was incorrect\n");
                }
                break;
            case 4:
                printf("enter index of the element\n");
                fgets(buffer, sizeof(buffer), stdin);
                ln = strlen(buffer) - 1;
                if (buffer[ln] == '\n')
                    buffer[ln] = '\0';
                if(checkIndex(buffer) == 0)
                    findByIndex(head, atoi(buffer));
                else
                    printf("Index was not a number\n");
                break;
            case 5:
                printf("enter firstname, lastname, email or phone number\n");
                fgets(buffer, sizeof(buffer), stdin);
                ln = strlen(buffer) - 1;
                if (buffer[ln] == '\n')
                    buffer[ln] = '\0';
                findByKey(head, buffer);
                break;
            case 6:
                printf("enter index\n");
                fgets(buffer, sizeof(buffer), stdin);
                ln = strlen(buffer) - 1;
                if (buffer[ln] == '\n')
                    buffer[ln] = '\0';
                if(checkIndex(buffer) == 0){
                    delete(&head, &tail, atoi(buffer));
                }
                else{
                    printf("Index was not a number\n");
                }
                break;
            case 7:
                deleteAll(&head);
                break;
            case 8:
                deleteAll(&head);
                exit(0);
                break;
            default:
                fprintf(stderr, "unknown command\n");
                printHelp();
                break;
        }
    }
    deleteAll(&head);
    return 0;
}

void populateList(){
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222220");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222221");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222222");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222223");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222224");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222225");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222226");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222227");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222228");
    insertAtTheEnd(&head, &tail, "Jonas Jonauskas jonas@gmail.com 862222229");
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