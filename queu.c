#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void enqueue();
void dequeue();
void display();
int queue[MAX];
int front=-1;
int rear=-1;
int main()
{
int choice;
while(1){
printf("1.enque(insert elemnt to queue)\n");
printf("2.deque(delete elemnt from queue)\n");
printf("3.disply all elemnt elemnt of queue)\n");
printf("4.quit)\n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
  case 1:
      enqueue();
 break;
  case 2:
      dequeue();
      break;
  case 3:
      display();
      break;
  case 4:
     exit(0);
default:printf("wrong choice,please try again.\n");
}
}
return 0;
}
  void enqueue()
{
 int item;
if(rear==MAX-1)
{
printf("queue overflow\n");
}
else
{
 if(front==-1)
{
front=0;
}
printf("insert the elemnt in queue:");
scanf("%d",&item);
rear ++;
queue[rear]=item;
}}
void dequeue()
{
if(front ==-1||front>rear)
{
printf("queue underflow\n");
}
else
{
printf("element deleted from queue:%d\n",queue[front]);
}
front ++;
}
void display()
{
int i;
if(front==-1||front>rear)
{
printf("queue is empty\n");
}
else
{
printf("queue elmnts:");
for(i=front;i<=rear;i++)
{
printf("%d",queue[i]);
}
printf("\n");
}
}



