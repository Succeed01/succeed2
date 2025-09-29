#include"doublynode.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,a,b;
    list nod;
    printf("Enter the lent of the Node: ");
    scanf("%d",&n);
    nod= createnode(n);

    printf("Enter the value that you wannt to add on the head: ");
    scanf("%d",&a);
    nod=inserthead(nod,a);
    display(nod);
    
    printf("Enter the value that you wannt to add at the end: ");
    scanf("%d",&b);
    nod= insertend(nod,b);
    display(nod);

    return 0;
}

