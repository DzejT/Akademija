
struct node{
    char firstname[20];
    char lastname[20];
    char email[50];
    char phone[15];
    struct node* next;
};


int insertAtTheEnd(struct node** head, struct node** tail, char *str);
int insertByTheIndex(struct node** head, struct node** tail, char *str);
void display(struct node* head);
void findByKey(struct node* head, char *key);
void findByIndex(struct node* head, int index);
void delete(struct node** head, struct node** tail, int index);
void deleteAll(struct node** head);
int checkIndex(char *str);

