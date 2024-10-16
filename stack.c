#include<stdio.h>
void push();
void pop();
void display();
int stack[10],i,j,n,choice=0,top=-1;
void main()
{
printf("enter the elemnts in the stack:");
scanf("%d",&n);
printf("\n \n");
while(choice!=4)
{
printf("choose one from the below option\n");
printf("\n 1.push \n2.pop \n3.display\n4.exit");
printf("\n enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("exiting.....");
break;
default:
printf("please enter valid choice");
}
}
}
void push()
{
int val;
if(top==n)
{
printf("\n overflow");
}
else
{
printf("enter the value:");
scanf("%d",&val);
top=top+1;
stack[top]=val;
}
}
void pop()
{
if(top==-1)
{
printf("under flow");
}
else
{
top=top-1;
}
}
 void display()
{
for(i=top;i>=0;i--)
{
printf("%d",stack[i]);
}
if(top==-1)
{
printf("stack is empty");
}
}

