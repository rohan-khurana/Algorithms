#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void producer();
void consumer();
int wait(int);
int signal(int);
int mutex=1,full=0,empty=0,x=0;
int main()
{
    int n,size;
    printf("Enter Size of Buffer: ");
    scanf("%d",&size);
    empty=size;
    printf("1.Producer\n2.Consumer\n3.Exit\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1: if((mutex==1)&&(empty!=0))
                producer();
                else
                printf("Buffer is FULL");
                break;
        case 2: if((mutex==1)&&(full!=0))
                consumer();
                else
                printf("Buffer is EMPTY");
                break;
        case 3:
                exit(0);
                break;
    }
}
getch();
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return(++s);
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("Producer Produces the Item %d\n",x);
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer Consumes Item %d\n",x);
    x--;
    mutex=signal(mutex);
}
