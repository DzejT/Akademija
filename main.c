#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"
#include "helpers.h"
#include<signal.h>


static int run_loop = 1;

static void signal_handler(int signo);


int main()
{   
    struct node *head = NULL;
    populateList(&head);
    printHelp();


    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while(run_loop)
    {
        switch(get_user_option()){
            case 1:
                display(head);
                break;
            case 2:
                add_new_address(&head);
                break;
            case 3:
                add_address_at_index(&head);
                break;
            case 4:
                find_at_position(head);
                break;
            case 5:
                find_by_keyword(head);
                break;
            case 6:
                delete_at_position(&head);
                break;
            case 7:
                deleteAll(&head);
                break;
            case 8:
                run_loop = 0;
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

static void signal_handler(int signo)
{
    printf("CTRL+C was pressed. Stopping program\n");
    run_loop = 0;
}

