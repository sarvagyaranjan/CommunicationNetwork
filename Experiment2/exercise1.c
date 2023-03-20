 #include<stdio.h>
#include<string.h>
#define N strlen(g)
char t2[28],t1[28],t[28],cs[28],g[30];
int a,e,c,b,d;
int i,j,k;
void exor()
{
    for(c = 1; c < N; c++)
        cs[c] = (( cs[c] == g[c])?'0':'1');
}
void crc()
{
    for(e=0; e<N; e++) cs[e]=t[e];
    do
    {
        if(cs[0]=='1') exor();
        for(c=0; c<N-1; c++)
            cs[c]=cs[c+1];
        cs[c]=t[e++];
    }
    while(e<=a+N-1);
}
int main()
{
    printf("\n*****RECEIVER SIDE ****\n\nEnter the CRC encoded message to be decoded, in binary format: ");
    scanf("%s",t);
    printf("\n----------------------------------------");
    printf("\nEnter Generating polynomial(Divisor) in binary : ");
    scanf("%s",g);
    a=strlen(t);
    for(i=0; i<a-3; i++)
    {
        t1[i] = t[i];
    }
    for(e=a; e<a+N-1; e++) t[e]='0';
    printf("\n----------------------------------------");
    printf("\n----------------------------------------");
    crc();
    printf("\nChecksum is : %s",cs);
    b=0;
    for(e=strlen(t1); e<a+strlen(cs)-3; e++)
    {
        for(j=0; j<strlen(cs); j++)
        {
            t1[e] = cs[j];
            b++;
        }
    }
    printf("\n----------------------------------------");
    printf("\nFinal message code word after division is : %s",t1);
    printf("\n----------------------------------------");
    for(k=0; k<strlen(t1)-3; k++)
    {
        t2[k] = t1[k];
    }
    printf("\nThe code word after decoding is : %s",t2);
    printf("\n----------------------------------------\n\n");

}
