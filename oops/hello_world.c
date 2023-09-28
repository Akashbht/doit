#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
//INSERT AT THE BEGINING
node* IAB(node *head )
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter Data to insert\t");
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
    return head;
}
void display(node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}
//INSERTION IN BETWEEN
node* IIB(node *head,int index,int value)
{
    node *temp,*ptr;
    ptr=head;
    int i=0;
    temp=(node*)malloc(sizeof(node));
    temp->data=value;
    while(i != index-1)
    {
        ptr=ptr->next;
        i++;
    }
    temp->next=ptr->next;
    ptr->next = temp;
    return head;
}
//INSERT AT THE END
node* IAE(node *head)
{
    node *temp;
    node *ptr;
    temp=(node*)malloc(sizeof(node));
    printf("Enter DATA %t");
    scanf("%d",&temp->data);
    ptr=head;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=NULL;
    return head;
}
int main()
{
    node *head=NULL;
    head=IAB(head);
    head=IAB(head);
    head=IAB(head);
    head=IAB(head);
    head=IAB(head);
    head=IAB(head);
    display(head);
    head=IIB(head,3,55);
    display(head);
    head=IAE(head);
    display(head);
}