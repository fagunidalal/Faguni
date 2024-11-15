#include <stdio.h>
#include <math.h>

int main() {
    int a,b,c,d,e,f,i,k,m,n,o,p;
    float j,l,g,h;
    int option;
    printf("THE FUNCTIONALITIES ARE MENTIONED BELOW:\n1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n5.LOGARITHMIC VALUES\n6.SQUARE ROOTS\nPICK AN OPERATION TO PERFORM:");
    scanf("%d",&option);
    printf("\n");
    switch (option)
{
    case 1:
    {printf("enter num1=");
    scanf("%d",&a);
    printf("enter num2=");
    scanf("%d",&b);
    printf("\naddition=%d",a+b);
    break;}
    case 2:
    {printf("enter num1=");
    scanf("%d",&c);
    printf("enter num2=");
    scanf("%d",&d);
    printf("\nsubtraction=%d",c-d);
    break;}
    case 3:
    {printf("enter num1=");
    scanf("%d",&e);
    printf("enter num2=");
    scanf("%d",&f);
    printf("\nmultiplication=%d",e*f);
    break;}
    case 4:
    {printf("enter num1=");
    scanf("%d",&g);
    printf("enter num2=");
    scanf("%d",&h);
    printf("\ndivision=%.2f",g/h);
    break;}
    case 5:
    {printf("enter num=");
    scanf("%d",&i);
    j=log(i);
    printf("\nlogarithmic value=%.2f",j);
    break;}
    case 6:
    {printf("enter num=");
    scanf("%d",&k);
    l=sqrt(k);
    printf("\nsquare root=%.4f",l);
    break;}
    default;
    printf("invalid");
    break;
}
    
    return 0;
}
