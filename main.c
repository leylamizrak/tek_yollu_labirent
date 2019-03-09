#include <stdio.h>
#include <stdlib.h>
///bu kodun amac ýtek yollu bir labirentte gidilecek yollarýn koordinatlarýný yazmaktýr.
struct n
{
    struct n *next;
    int x;
    int y;
    char eleman;
};
typedef struct n node;

int main()
{
    FILE *dosya=fopen("labirent.txt","r");

    if(dosya==NULL)
        printf("Dosya bulunamadi.\n");

    char dizi[12][15];

    int i=0,j=13;

    fgets(dizi[i],15,dosya);
    dizi[i][13]='\0';

    while(!feof(dosya))
    {
        i++;
        fgets(dizi[i],15,dosya);
        dizi[i][13]='\0';
    }

int sayac2=0;
    printf("       LABIRENT\n");

    for(i=0; i<12; i++)
    {
        for(j=0; dizi[i][j]!='\0'; j++)
        {
            printf("%c",dizi[i][j]);
            if(dizi[i][j]!='\n')
                printf(" ");
                if(dizi[i][j]=='0')sayac2++;
        }


    }

    node *root=(node*)malloc(sizeof(node));

    node *bas_son=(node*)malloc(sizeof(node));

    int sayac=0;

    for(i=0;i<12;i++)
    {
        for(j=0;dizi[i][j]!='\0';j++)
        {
            if(dizi[i][j]=='2')
            {
                bas_son->x=i;
                bas_son->y=j;
                bas_son->eleman=dizi[i][j];
                bas_son->next=NULL;

                if(dizi[i-1][j]=='0')
                {
                    root->eleman='4';
                    root->x=i-1;
                    root->y=j;
                    root->next=NULL;
                    sayac++;
                    break;
                }
                else if(dizi[i+1][j]=='0')
                {
                    root->eleman='4';
                    root->x=i+1;
                    root->y=j;
                    root->next=NULL;
                    sayac++;
                    break;
                }
                else if(dizi[i][j-1]=='0')
                {
                    root->eleman='4';
                    root->x=i;
                    root->y=j-1;
                    root->next=NULL;
                    sayac++;
                    break;
                }
                else if(dizi[i][j+1]=='0')
                {
                    root->eleman='4';
                    root->x=i;
                    root->y=j+1;
                    root->next=NULL;
                    sayac++;
                    break;
                }
            }
        }
                if(sayac==1)
                break;
    }

    printf("Baslangic Noktasi:(%d,%d)\n",bas_son->x+1,bas_son->y+1);

    node *yigin=NULL;

    yigin=(node*)malloc(sizeof(node));
    yigin->eleman=root->eleman;
    yigin->x=root->x;
    yigin->y=root->y;
    dizi[yigin->x][yigin->y]='4';
    yigin->next=NULL;

    node* yigin2=yigin;

    int sayac3=1;



    while(1)
    {
        sayac=0;
         for(i=0;i<12;i++)
    {
        for(j=0;dizi[i][j]!='\0';j++)
        {
            if(dizi[i][j]=='4')
            {
                if(dizi[i-1][j]=='0')
                {
                    root->eleman='4';
                    root->x=i-1;
                    root->y=j;
                    root->next=NULL;
                    sayac++;
                    break;
                }
                else if(dizi[i+1][j]=='0')
                {
                    root->eleman='4';
                    root->x=i+1;
                    root->y=j;
                    root->next=NULL;
                    sayac++;
                    break;
                }
                else if(dizi[i][j-1]=='0')
                {
                    root->eleman='4';
                    root->x=i;
                    root->y=j-1;
                    root->next=NULL;
                    sayac++;
                    break;
                }
                else if(dizi[i][j+1]=='0')
                {
                    root->eleman='4';
                    root->x=i;
                    root->y=j+1;
                    root->next=NULL;
                    sayac++;
                    break;
                }
            }
        }
                if(sayac==1)
                break;
    }

    for(i=0;i<12;i++)
    {
        for(j=0;dizi[i][j]!='\0';j++)
        {
            if(dizi[i][j]=='3')
            {
                bas_son->x=i;
                bas_son->y=j;
            }
        }
    }


           yigin->next=(node*)malloc(sizeof(node));
           yigin=yigin->next;
           yigin->eleman=root->eleman;
           yigin->x=root->x;
           yigin->y=root->y;
           dizi[yigin->x][yigin->y]='4';
           yigin->next=NULL;

           sayac3++;

            if(sayac2==sayac3)break;


    }
    free(root);

    while(yigin2!=NULL)
    {
        printf("(%d,%d)\n",yigin2->x+1,yigin2->y+1);
        yigin2=yigin2->next;
    }

   printf("Bitis Noktasi:(%d,%d)\n",bas_son->x+1,bas_son->y+1);

   free(bas_son);

   return 0;
}
