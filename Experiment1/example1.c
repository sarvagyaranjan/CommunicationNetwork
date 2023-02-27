#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int i,j;
void sender(int b[10],int k)
{
 int checksum,sum=0;
 printf("\n****SENDER****\n");
 for( i=0;i<k;i++)
 sum+=b[i];
 printf("SUM IS: %d\n",sum);
 checksum=~sum;
 printf("\nSENDER's CHECKSUM IS:%d",checksum);
}
int main()
{
char str[100], bstr[100];
 int a[100],m,scheck;
 char choice;
 printf("\n.....YOUR OPTIONS....\n");
 printf("\na.Checksum\nb. Bit stuffing\nc. Character count\n");
 printf("\nEnter your choice:");
 scanf("%c",&choice);
 switch(choice)
 {
 //Checksum Calculation
 case 'a':
 {
 printf("\nENTER SIZE OF THE STRING:");
 scanf("%d",&m);
 printf("\nENTER THE ELEMENTS OF THE ARRAY:");
 for(i=0;i<m;i++)
 scanf("%d",&a[i]);
 sender(a,m);
}
 break;
 //Bit stuffing
 case 'b':
 {
 int count=0;
 printf("Enter the bit string: ");
 scanf("%s",str);
 for(i=j=0; str[i]; i++)
 {
if(str[i]=='1') count++;
 else count=0;
 bstr[i+j]=str[i];
 if(count==5)
 {
 j++;
 bstr[i+j]='0';
 count=0;
}
}
 bstr[i+j]='\0';
 printf("\nAfter Bit stuffing : %s\n", bstr);
 }
 break;
 //Inserting character count code
 case 'c':
 {
 char arr[100]; int x,y;
 printf("\nENTER THE ELEMENTS OF THE ARRAY:");
 scanf("%s",arr);
 printf("\n Resultant Frame using character count = %d%s\n",strlen(arr)+1,arr);
 }
 break;
 default:
 printf("\nYou entered an invalid choice run program again");
}
 getch();
}
