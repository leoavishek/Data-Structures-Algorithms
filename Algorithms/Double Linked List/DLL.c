//DOUBLE LINKED LIST
//AYUSH MOHANTY
#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
void main ()  
{  
    int choice =0;  
    while(choice != 8)   
    {  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");    
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 7:  
            display();        
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            randominsert();       
            break;
            case 4:  
            begin_delete();        
            break;  
            case 5:
            last_delete();
            break;
            case 0:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void beginsert()  
{
    int n;
    printf("enter N");
    scanf("%d",&n);
    struct node *p;
    p=(struct node *) malloc(sizeof(struct node *));  
    p->data=n;
    p->next=head;
    head=p;
}
void lastinsert (){
    int n;
    printf("enter N");
    scanf("%d",&n);
    struct node *p;
    p=(struct node *) malloc(sizeof(struct node *));  
    struct node *l;
    l=(struct node *) malloc(sizeof(struct node *));
    l=head;
    while(l->next!=NULL){
        l=l->next;
    }
    p->data=n;
    p->next=NULL;
    l->next=p;
}
void randominsert(){
    int n,loc;
    printf("enter N ");
    scanf("%d",&n);
    printf("enter loc of index ");
    scanf("%d",&loc);
    struct node *l;
    l=(struct node *) malloc(sizeof(struct node *));
    l=head;
    while (loc!=0){
        loc=loc-1;
        l=l->next;
    }
    struct node *p;
    p=(struct node *) malloc(sizeof(struct node *));  
    p->data=n;
    p->next=l->next;
    l->next=p;
}
void begin_delete(){
    struct node *l;
    l=(struct node *) malloc(sizeof(struct node *));
    l=head;
    head=l->next;
    free(l);
}
void last_delete(){
    struct node *l;
    l=(struct node *) malloc(sizeof(struct node *));
    l=head;
    while(l->next->next!=NULL){
        l=l->next;
    }
    l->next=NULL;
    free(l->next);
}
void random_delete(){
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n\n");   
        while (ptr!=NULL)  
        {  
            printf("%d->",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}

