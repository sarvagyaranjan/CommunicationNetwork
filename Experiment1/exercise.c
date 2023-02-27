#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

int i,j;

void receiver(int b[10],int k)
{
    int checksum,sum=0;
    printf("\n****RECEIVER****\n");
    for(i=0;i<k;i++)
        sum+=b[i];
    printf("SUM IS: %d",sum);
    checksum=~sum;
    printf("\nRECEIVER's CHECKSUM IS:%d",checksum);
    int errorDetection = ~(checksum+sum);
    printf("\nERROR DETECTION:%d",errorDetection);
    if(errorDetection==0)
        printf("\n\nACCEPTED");
    else
        printf("\n\nREJECTED");
}

int main()
{
    char str[100], bstr[100];
    int a[100],m,scheck;
    char choice;
    printf("\n.....YOUR OPTIONS....\n");
    printf("\na. Checksum\nb. Bit destuffing\nc. Character count\n");
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
            receiver(a,m);
        }
        break;
        //Bit stuffing
        case 'b':
        {
            int count=0;
            printf("Enter the bit stuffed string: ");
            scanf("%s",str);
            for(i=j=0; str[i]!='\0'; i++)
            {
                if(str[i]=='1')
                count++;
                else
                count=0;
                bstr[i-j]=str[i];
                if(count==5)
                {
                    i++;
                    j++;
                    count = 0;
                }

            }
            bstr[i-j] = '\0';
            printf("\nBefore Bit stuffing :  %s\n", bstr);
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
