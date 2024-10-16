#include<stdio.h>
int main()
{
int i,n,small,large;
printf("enter the size of an array");
scanf("%d",&n);

int a[n];
printf("enter the elments:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
small=a[0];
large=a[0];
for(i=1;i<n;i++)
{
if(a[i]<small)
small=a[i];
if(a[i]>large)
large=a[i];
}
printf("smallest numbe:%d",small);
printf("largest number:%d",large);
return 0;
}

