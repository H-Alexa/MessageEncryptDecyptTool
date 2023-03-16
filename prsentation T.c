#include<stdio.h>

char ar[100000];
void encrypt();
void decrypt();
void accept();
int gcd(int a,int b);


int main()
{
    int choice;
    char c;
    printf("*********************Welcome to IIT-09 security system*********************\n");
    while(1)
    {
        printf("\n\nSelect one option:\n1.Encrypt plain text\n2.Decrypt cipher text\n"); /*Select one option. Press 1 for encrypting and press 2 for decrypting.*/
        scanf("%d",&choice);
        if(choice==1)
            encrypt(); /*Calling a function for encrypting text*/
        else
            decrypt(); /*Calling a function for decrypting text.*/

        printf("\n\nDo you want to continue? (Y/N)\n");


        scanf("%c",&c);
        if(c=='N')
        {
            printf("**********Thank you.**************\n");
            break;
        }

    }


    return 0;
}



void encrypt()
{
    int i,k1,k2,count;
    char c;

    printf("Enter key1: (A number) \n\n");
    scanf("%d",&k1);

    if(gcd(k1,26)!=1)   /*Calling the gcd function here. If the gcd of k1 and 26 is not equal to 1, we won't be able to apply the extended Euclidian algorithm here. Hence, it will be an invalid input, and the function will return.*/
    {
        printf("\nInvalid input\n");
        getchar();
        return;
    }

    printf("Enter key2: (Another number) \n\n");
    scanf("%d",&k2);

    if(k2>=26)
    {
        printf("\nInvalid input\n"); /*If k2 is greater than or equal to 26, we won't be able to find out the additive inverse of k2 with respect to 26. Hence, it'll be an invalid input.*/
        getchar();
        return;
    }

    getchar();
    printf("\nEnter your plaintext message: ");
    gets(ar);
    printf("\nEncrypted text: "); /*The final output*/
    for(i=0; ar[i]!='\0'; i++)
    {
        if(ar[i]>='A'&&ar[i]<='Z')
        {
            ar[i]=ar[i]-'A';
            c=((ar[i]*k1)+k2)%26; /*Affine cipher rule*/
            printf("%c",c+'A');

        }
        else if(ar[i]>='a'&&ar[i]<='z')
        {
            ar[i]=ar[i]-'a';
            c=((ar[i]*k1)+k2)%26;  /*Affine cipher rule*/
            printf("%c",c+'a');
        }
        else
            printf("%c",ar[i]);

    }
    printf("\n\n\n");

}

void decrypt()
{
    int i,k1,k2,count,t1,t2,r,r1,r2,t,q;
    char c;

    printf("Enter key1: ");
    scanf("%d",&k1);

    if(gcd(k1,26)!=1)
    {
        printf("\nInvalid input\n"); /*Calling the gcd function here. If the gcd of k1 and 26 is not equal to 1, we won't be able to apply the extended Euclidian algorithm here. Hence, it will be an invalid input, and the function will return.*/
        getchar();
        return;
    }
    printf("Enter key2: ");
    scanf("%d",&k2);
    if(k2>=26)
    {
        printf("\nInvalid input\n"); /*If k2 is greater than or equal to 26, we won't be able to find out the additive inverse of k2 with respect to 26. Hence, it'll be an invalid input.*/
        getchar();
        return;
    }
    k2=26-k2;
    getchar();
    r1=26;
    r2=k1;
    t1=0;
    t2=1;
    while(r2>0)
    {
        q=r1/r2;
        r=r1%r2;
        r1=r2;
        r2=r;
        t=t1-(q*t2);
        t1=t2;
        t2=t;
    }
    k1=t1;
    if(t1<0)
        k1=26+t1; /*Determined the value of the multiplicative inverse of k1 and assigned it into variable k1.*/


    printf("\nEnter encrypted text: ");
    gets(ar);
    printf("\nplain text: ");
    for(i=0; ar[i]!='\0'; i++)
    {
        if(ar[i]>='A'&&ar[i]<='Z')
        {
            ar[i]=ar[i]-'A';
            c=((ar[i]+k2)*k1)%26; /*Affine cipher rule*/
            printf("%c",c+'A');

        }
        else if(ar[i]>='a'&&ar[i]<='z')
        {
            ar[i]=ar[i]-'a';
            c=((ar[i]+k2)*k1)%26; /*Affine cipher rule*/
            printf("%c",c+'a');
        }
        else
            printf("%c",ar[i]);

    }
    printf("\n\n\n");
}

int gcd(int a, int b)
{
    if(b==0)
        return a;
    if(a==0)
        return b;
    int temp;
    while(b>0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
