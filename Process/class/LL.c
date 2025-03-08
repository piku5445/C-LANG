#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int info;
    struct node *link;
}Node;

void create(Node **,int);
Node * createNode(int);
void insertEnd(Node *,int);
void insertBeg(Node **,int);
void insertAny(Node *,int,int);
int deleteByelem(Node**,int);

void display(Node *);
bool isEmpty(Node *);


int main(){
    Node *head=NULL;
    int n,item;
    do{
        printf("1. Create// Insert\n");
        printf("2. Delete a Node\n");
        printf("9. Display\n");
        printf("0. Quit\n");

        printf("Choice : ");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
            printf("Enter a number to insert");
            scanf("%d",&item);
            create(&head,item);
            break;
        case 2:
            printf("Enter a number to insert");
            scanf("%d",&item);
            // addElem()
            break;
        case 9:
            printf("Displaying List\n");
            display(head);
            break;       
        case 0:
            printf("Thank You\n");
            break;       
        default:
            printf("Invalid Choice:\n");
        }
    }while (n!=0);

    
    return 0;
}
Node * createNode(int item){
    Node *n = (Node *)malloc(sizeof(Node));
    n->info = item;
    n->link = NULL;
    return n;
}
void create(Node **head,int item){
    if (isEmpty(*head)){
        Node *new = createNode(item);
        *head = new;
    }else{
        int loc;
        printf("List is Non-empty. Enter the position: (1: begining, 0: end, +ve : for any loc)");
        scanf("%d",&loc);
        int count_ll  = count(*head);
        if(loc == 1){
            insertBeg(head,item);
        }else if (loc == 0 || loc>=count_ll){
            insertEnd(*head,item);
        }else{
            insertAny(*head,item,loc);
        }

    }
}
void display(Node *head){
    Node * temp  = head;
    while(temp){
        printf("%5d",temp->info);
        temp = temp->link;
    }
    printf("\n");
}
bool isEmpty(Node *head){
    return !head;
}
void insertEnd(Node *head,int item){
    Node *new = createNode(item);
    Node *temp = head;
    while(temp->link){
        temp = temp->link;
    }
    temp->link = new;
}
void insertBeg(Node **head,int item){
    Node *new = createNode(item);
    new->link = *head;
    *head = new;
}
void insertAny(Node *head,int item,int loc){
    Node * new = createNode(item);
    Node * temp = head;
    loc-=2;
    while (loc--){
        temp = temp ->link;
    }
    new->link = temp->link;
    temp->link = new;
}
int deleteByelem(Node** head,int item){
    int loc = search(*head,item);
    int numCount = count(*head);
    if (isEmpty(*head) || loc == -1)
        printf("Either List Empty or Element not in list\n");
    else if(loc == 1)
        deleteBeg(head);
    else if(loc == numCount)
        deleteEnd(*head);
    else
        deleteAny(*head,loc);
}
int deleteBeg(Node **head){
    if (isEmpty(*head)){
        printf("List is empty\n");
        return -1;
    }
    Node *temp = *head;
    *head = temp->link;
    int elem = temp->info;
    free(temp);
    return elem;
}
int deleteEnd(Node *head){
    if (isEmpty(head)){
        printf("List is empty\n");
        return -1;
    }
    Node *temp = head;
    Node *temp2 =head->link;
    while(temp2->link){
        temp=temp->link;
        temp2=temp2->link;
    }
    Node *temp3 = temp->link;
    temp->link = NULL;
    int elem = temp3->info;
    free(temp3);
    return elem;
}

int count(Node *head){
    int count = 1;
    if (head == NULL)
        return 0;
    while(head){
        count++;
        head=head->link;
    }
    return count;
}
int serach(Node *head,int item){
    int count = 1;
    if (head == NULL)
        return -1;
    while(head){
        if(head->info == item)
            return count;
        count++;
        head=head->link;
    }
    return -1;
}




