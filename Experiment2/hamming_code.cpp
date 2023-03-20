#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>
#include <math.h>
#include<iostream>



int main(void)
{
 unsigned int m=0,r=0,l=0,x1=1,x2=1,x0=0;
 char d[1024]= {0};
 int d1[1024],d2[1024];
 printf("Enter the message to be encoded, in binary format: ");
 scanf ("%s",&d);
//Message Length
 m=strlen(d);
//Check bits (r)
 for (int i=0; i<20; i++)
 {
 r=i;
 if(m+1+i <= pow(2,i))
    break;
 }
//Codeword length (l)
 l = m+r;
//Testing the input in binary
 for (int i=0; i<m; i++)
 {
 while (!( d[i]=='0' || d[i]=='1'))
 {
 printf("\nPlease enter the input message in binary only.\n");
 exit(0);
 }
 }
 printf ("\nMessage length (m) = %d\n",m);
 printf ("Redundancy bits (r) = %d\n",r);
 printf("Codewordlength (l) = %d\n",l);
//Initialization to zero
 for (int i=m; i<1024;i++)
 d[i]='0';
 for (int i=0; i<1024; i++)
    { d1[i]=0; d2[i]=0; }
//Copying string array to intarray, also shifting start index from 0 to 1
 for (int i=0; i<m+1; i++)
 {
 if (d[i]=='1') d1[i+1]=1;
 else d1[i+1]=0;
 }
//Shifting message bits into non parity positions
 for (int x2=1; x2<m+r+1; x2++)
 {
     float x = (log(x2)/log(2))-(int(log(x2)/log(2)));
     if(x==0 || x==1)
     { d2[x2]=0; x0=x0+1; }
     else d2[x2]=d1[x2-x0];
     //Finding parity bits
     for(int x2=1; x2<m+r+1; x2++)
     {
     int x2t=x2;
     for(int i=0; i<r; i++)
     {
         int ipow=pow(2,i);
     if (x2t%2==1)
     d2[ipow]=d2[ipow] ^ d2[x2];
     x2t=x2t/2;
     }
     }
     printf("Code word: ");
     for (int i =1; i<m+r+1; i++)
     for (int i =1; i<m+r+1; i++)
     printf ("%d",d2[i]);
     printf("\n\n");
}
}
