
struct node{
    char firstname[25];
    char lastname[25];
    char email[50];
    char phone[25];
    struct node* next;
};

void display(struct node* head);
void findByKey(struct node* head, char *key);
void findByIndex(struct node* head, int index);
void delete(struct node** head, int index);
void deleteAll(struct node** head);
struct node* createNode(char *name, char *surname, char *email, char *number);
void add_to_list(struct node **list, struct node *address);
void print_node(struct node *address);
void add_to_list_at_index(struct node **list, struct node *address, int index);