#include<stdio.h>
#include<stdlib.h>
int n,count=0;
void insert_begin();
void insert_end();
void insert_pos();
void traversal();
void delt_begin();
void delt_end();
void delt_pos();

struct node{
      int data;
      struct nod*next;
};
    struct node*head=NULL,*newnode,*temp,*prev;
int main()
{
   int ch;
   while(ch!=0)
{
printf("\n enter your choice:\n 1.insert at begining\n2.inset at end\n3.insertat a positon\ntraversal\n.deletion at begining\n.deletion at end\n7.deletion at a position\n8.exit");
scanf("%d",&ch);
switch(ch)
{
   case 1:
   insert_begin();
   break;
   case 2:
   insert_end();
   break;
   case 3:
   insert_pos();
   break;
   case 4:
   traversal();
   break;
   case 5:
   delt_begin();
   break;
   case 6:
   delt_end();
   break;
   case 7:
   delt_pos();
   break;
default:printf("invalid choice");
}
}}
void insert_begin()
{
 newnode=(struct node*)malloc(sizeof(struct node*));
printf("enter the data:\t");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
traversal();
count++;
}
void traversal()
{
if(head==NULL)
{
printf("no node is presant");
}
else
{
temp=head;
while(temp->next!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("%d",temp->data);
}
}
 void insert_end()
{
 newnode=(struct node*)malloc(sizeof(struct node*));
printf("enter the data:\t");
scanf("%d",&newnode->data);
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
 temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
newnode->next=NULL;
temp=newnode;
}
traversal();
count++;
}


void insert_pos()
{
 newnode=(struct node*)malloc(sizeof(struct node*));
printf("enter the data:\t");
scanf("%d",&newnode->data);
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
 printf("enter the location to insert:");
scanf("%d",&n);
if(n>count)
{
  printf("insertion not posible");
}
else
{
int i=1;
temp=head;
while(i<n)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;
}
}
traversal();
count++;
}
 void delt_begin()
{
if(head==NULL)
{
printf("no node found");
}
else
{
temp=head;
head=temp->next;
free(temp);
}
traversal();
count--;
}
void delt_end()
{
if(head==NULL)
{
printf("no node found");
}
else
{
temp=head;
while(temp->next!=NULL)
{
 prev=temp;
temp=temp->next;
}
prev->next=NULL;
free(temp);
}
traversal();
count--;
}
void delt_pos()
{
if(head==NULL)
{
printf("no node found");
}
else
{
printf("enter the location to delete:");
scanf("%d",&n);
if(n>count)
{
  printf("deletion not possible");
}
else
{
 int i=1;
prev=head;
while(i<n-1)
{
prev=prev->next;
i++;
}
temp=prev->next;
prev->next=temp->next;
free(temp);
}
}
traversal();
count--;
}
void search()
{
int search,a=0,i=1;
printf("enter the elemnt:");
scanf("%d",&search);
if(head==NULL)
{
printf("no node is presant");
}
else
{
temp=head;
while(temp->next!=NULL)
{
if(temp->data==search)
{
a=1;
printf("its found @%d position,i");
break;
}
temp=temp->next;
i++;
}
if(a==0)
{
printf("not found");
}
}}

