#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[30];
int a,e,c;
void exor()
{
for(c = 1;c < N; c++)
 cs[c] = (( cs[c] == g[c])?'0':'1');
}
void crc()
{
 for(e=0;e<N;e++) cs[e]=t[e];
 do{
     if(cs[0]=='1') exor();
     for(c=0;c<N-1;c++)
         cs[c]=cs[c+1];
         cs[c]=t[e++];
 }
 while(e<=a+N-1);
}
int main()
{
 printf("\nEnter data : ");
 scanf("%s",t);
 printf("\n----------------------------------------");
 printf("\nEnterGenerating polynomial in binary : ");
 scanf("%s",g);
 a=strlen(t);
 for(e=a;e<a+N-1;e++)
    t[e]='0';
 printf("\n----------------------------------------");
 printf("\nAugmenteddataword : %s",t);
 printf("\n----------------------------------------");
 crc();
 printf("\nChecksum is : %s",cs);
 for(e=a;e<a+N-1;e++) t[e]=cs[e-a];
    printf("\n----------------------------------------");
 printf("\nFinalcodeword is : %s",t);
 printf("\n----------------------------------------\n\n");
 return 0;
}
