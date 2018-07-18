#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void lbox(int x,int y)
{
    int i;
    gotoxy(x,y+2);
    printf("%c",201);
    for(i=x+1; i<x+15; i++)
    {
        gotoxy(i,y+2);
        printf("%c",205);
    }
    gotoxy(x+15,y+2);
    printf("%c",187);
    gotoxy(x,y+2);
    for(i=y+2; i<y+5; i++)
    {
        gotoxy(x,i+1);
        printf("%c",186);
    }
    gotoxy(x,y+5);
    printf("%c",200);
    for(i=x+1; i<x+15; i++)
    {
        gotoxy(i,y+5);
        printf("%c",205);
    }
    gotoxy(x+15,y+5);
    printf("%c",188);
    gotoxy(x+15,y+2);
    for(i=y+2; i<y+2+2; i++)
    {
        gotoxy(x+15,i+1);
        printf("%c",186);
    }
}

void lbox4(int x,int y)
{
    int i;
    gotoxy(x,y+2);
    printf("%c",201);
    for(i=x+1; i<x+25; i++)
    {
        gotoxy(i,y+2);
        printf("%c",205);
    }
    gotoxy(x+25,y+2);
    printf("%c",187);
    gotoxy(x,y+2);
    for(i=y+2; i<y+5; i++)
    {
        gotoxy(x,i+1);
        printf("%c",186);
    }
    gotoxy(x,y+5);
    printf("%c",200);
    for(i=x+1; i<x+25; i++)
    {
        gotoxy(i,y+5);
        printf("%c",205);
    }
    gotoxy(x+25,y+5);
    printf("%c",188);
    gotoxy(x+25,y+2);
    for(i=y+2; i<y+2+2; i++)
    {
        gotoxy(x+25,i+1);
        printf("%c",186);
    }
}

void lbox3(int x,int y)
{
    int i;
    gotoxy(x,y+2);
    printf("%c",201);
    for(i=x+1; i<x+11; i++)
    {
        gotoxy(i,y+2);
        printf("%c",205);
    }
    gotoxy(x+11,y+2);
    printf("%c",187);
    gotoxy(x,y+2);
    for(i=y+2; i<y+5; i++)
    {
        gotoxy(x,i+1);
        printf("%c",186);
    }
    gotoxy(x,y+5);
    printf("%c",200);
    for(i=x+1; i<x+11; i++)
    {
        gotoxy(i,y+5);
        printf("%c",205);
    }
    gotoxy(x+11,y+5);
    printf("%c",188);
    gotoxy(x+11,y+2);
    for(i=y+2; i<y+2+2; i++)
    {
        gotoxy(x+11,i+1);
        printf("%c",186);
    }
}

struct contact
{
    char name[1000],add[1000],email[1000];
    long long m_no;
} phn;

char query[1000],name[1000];
FILE *fp,*fp2,*ft;
int ch,tt,i,found,l,xx,yy,zz;

int main()
{
main:
ff:
    system( "cls" );

    char s[100],s1[100],s2[100];
    long long int x,y;
    gotoxy(21,6);
    printf( "**** Welcome to contact Manager ****" );
    lbox(7,8);
    gotoxy(10,12);
    printf("[1]ADD NEW");
    lbox3(23,8);
    gotoxy(24,12);
    printf("[2]SEARCH");
    lbox3(35,8);
    gotoxy(37,12);
    printf("[3]EDIT");
    lbox3(47,8);
    gotoxy(48,12);
    printf("[4]DELETE");
    lbox3(59,8);
    gotoxy(61,12);
    printf("[0]EXIT");

    zz=19;
    fflush(stdin);
    found=0;
    for(i=97; i<=122; i++)
    {
    fp=fopen( "contact.dat", "r" );
        while(fscanf(fp,"%s %lld %s %s",phn.name,&phn.m_no,phn.add,phn.email)!=EOF)
        {
            if (phn.name[0]==i || phn.name[0]==i-32)
            {
                gotoxy(17,++zz);
                printf("Name: %s",phn.name);
                gotoxy(17,++zz);
                printf("Phone: %lld",phn.m_no);
                gotoxy(17,++zz);
                printf("Address: %s",phn.add);
                gotoxy(17,++zz);
                printf("Email: %s",phn.email);
                ++zz;
            }
        }
        fclose(fp);
    }

    gotoxy(27,6);
    printf( "\n                               Enter the choice:" );
    scanf( "%d",&ch);
    switch (ch)
    {
    case 0:
        gotoxy(15,62);
        printf( "Are you sure u want to exit?" );
        break;
    case 1:    /* *********************add new contacts************ */
        system( "cls" );
        fp=fopen( "contact.dat","r");
        fp2=fopen("temp.dat","w");
        for (;;)
        {
            fflush(stdin);
            printf( "To exit enter blank space in the name input\n\nName : " );
            gets(phn.name);
            if ((strlen(phn.name)==1||strlen(phn.name)==0)&&isalpha(phn.name[0])==0)
                break;
            fflush(stdin);
            printf( "Phone No: " );
            scanf( "%lld",&phn.m_no);
            fflush(stdin);
            printf( "address:" );
            gets(phn.add);
            fflush(stdin);
            printf( "email address:" );
            gets(phn.email);
            printf( "\n" );
            y=0;
            int xx=0;
            while(fscanf(fp,"%s %lld %s %s",s,&x,s1,s2)!=EOF)
            {
                y=1;
                if (strcmp(phn.name,s)==-1&&xx==0)
                {
                    xx=1;
                    fprintf(fp2,"%s %lld %s %s\n",phn.name,phn.m_no,phn.add,phn.email);
                    fprintf(fp2,"%s %lld %s %s\n",s,x,s1,s2);
                }
                else
                    fprintf(fp2,"%s %lld %s %s\n",s,x,s1,s2);
            }
            if(y==0)
                fprintf(fp2,"%s %lld %s %s\n",phn.name,phn.m_no,phn.add,phn.email);
        }
        fclose(fp);
        fclose(fp2);
        remove( "contact.dat" );
        rename( "temp.dat","contact.dat");
        break;

    case 2:    /* *******************search contacts********************** */
S:
        system( "cls" );
        int XX=0,ii,jj,kk;
        do
        {
            found=0;
            printf( "\n\n\tCONTACT SEARCH\n\t===========================\n\n" );
            printf("\t\t1.Search By name\n\n\t\t2.Search By number\n\n\t\t0.Cancel\n\n");
            fflush(stdin);
            scanf("%d",&tt);
            getchar();
            if(tt==1)
            {
                gotoxy(1,13);
                printf("Search for: ");
                lbox4(13,10);
                gotoxy(14,13);
                gets(query);
                fp=fopen( "contact.dat", "r" );
                system( "cls" );
                printf( "\n\nSearch result for '%s' \n===================================================\n",query);
                while(fscanf(fp,"%s %lld %s %s",phn.name,&phn.m_no,phn.add,phn.email)!=EOF)
                {
                    XX=0;
                    for(ii=0; ii<=abs(strlen(phn.name)-strlen(query)); ii++)
                    {
                        kk=ii;
                        for(jj=0; jj<strlen(query); jj++)
                        {
                            if(query[jj]==phn.name[kk]||(query[jj]>=97&&toupper(query[jj])==phn.name[kk]))
                                kk++;
                            else
                                break;
                        }
                        if(jj==strlen(query))
                        {
                            XX=1;
                            break;
                        }
                    }
                    if (XX==1)
                    {
                     printf( "\nName\t: %s\nPhone\t: %lld\nAddress\t: %s\nEmail\t: %s\n",phn.name,phn.m_no,phn.add,phn.email);
                        found++;
                        if (found%4==0)
                        {
                            printf( "Press any key to continue..." );
                            getch();
                        }
                    }
                }
                if (found==0)
                    printf( "\nNo match found!");
                else
                    printf( "\n%d match(s) found!",found);
                fclose(fp);
            }
            else if(tt==2)
            {
                gotoxy(1,13);
                printf("Search for: ");
                lbox4(13,10);
                gotoxy(14,13);
                scanf("%lld",&y);
                fp=fopen( "contact.dat", "r" );
                system( "cls" );
                printf( "\n\nSearch result for '%lld' \n===================================================\n",y);
                while(fscanf(fp,"%s %lld %s %s",phn.name,&phn.m_no,phn.add,phn.email)!=EOF)
                {
                    if (y==phn.m_no)
                    {
                        printf( "\nName\t: %s\nPhone\t: %lld\nAddress\t: %s\nEmail\t:%s\n"//
                               ,phn.name,phn.m_no,phn.add,phn.email);
                        found++;
                        if (found%4==0)
                        {
                            printf( "Press any key to continue..." );
                            getch();
                        }
                    }
                }
                if (found==0)
                    printf( "\nNo match found!");
                else
                    printf( "\n%d match(s) found!",found);
                fclose(fp);
            }
            else if(tt==0)
                goto ff;
            else
            {
                printf("INVALIDE CHOICE......");
                Sleep(600);
                goto S;
            }
            printf( "\nTry again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf( "%d",&ch);
        }
        while(ch==1);
        break;
    case 3:   /* *********************edit contacts************************/
        tt=0;
        int T;
        system( "cls" );
        fp=fopen( "contact.dat", "r");
        ft=fopen( "temp.dat", "w");
        fflush(stdin);
        printf( "Edit contact\n===========================\n\n\tEnter the name of contact to edit:" );
        gets(name);
        while(fscanf(fp,"%s %lld %s %s",phn.name,&phn.m_no,phn.add,phn.email)!=EOF)
        {
            if (strcmp(name,phn.name)==0)
            {
                tt=1;
                fflush(stdin);
E:
                system("cls");
                printf( "\n\n\t\tEditing '%s'\n\n",name);
                printf("\t\t1.EDIT NAME\n\n\t\t2.EDIT PHONE\n\n\t\t 3.EDIT ADDRESS\n\n\t\t4.EDIT EMAIL\n\n\t\t0.CANCEL\n\n");
                scanf("%d",&T);
                getchar();
                if(T==1)
                {
                    printf("New Name: ");
                    gets(s);
                    fflush(stdin);
                    y=phn.m_no;
                    strcpy(s1,phn.add);
                    strcpy(s2,phn.email);
                }
                else if(T==2)
                {
                    printf("New Phone: " );
                    scanf( "%lld",&y);
                    fflush(stdin);
                    strcpy(s,phn.name);
                    strcpy(s1,phn.add);
                    strcpy(s2,phn.email);
                }
                else if(T==3)
                {
                    printf( "New address: " );
                    gets(s1);
                    fflush(stdin);
                    strcpy(s,phn.name);
                    y=phn.m_no;
                    strcpy(s2,phn.email);
                }
                else if(T==4)
                {
                    printf( "New email address: " );
                    gets(s2);
                    fflush(stdin);
                    strcpy(s,phn.name);
                    y=phn.m_no;
                    strcpy(s1,phn.add);
                }
                else if(T==0)
                {
                    strcpy(s,phn.name);
                    y=phn.m_no;
                    strcpy(s1,phn.add);
                    strcpy(s2,phn.email);
                }
                else
                {
                    printf("INVALIDE CHOICE......");
                    Sleep(600);
                    goto E;
                }
                printf( "\n" );
                fprintf(ft,"%s %lld %s %s\n",s,y,s1,s2);
            }
            else
                fprintf(ft,"%s %lld %s %s\n",phn.name,phn.m_no,phn.add,phn.email);
        }
        fclose(fp);
        fclose(ft);
        remove( "contact.dat" );
        rename( "temp.dat","contact.dat");
        if(tt==0)
            printf("Contact not found!!\n");
        break;
    case 4:    /* ********************delete contacts**********************/
        system( "cls" );
        fflush(stdin);
        printf( "\n\n\tDELETE A CONTACT\n\t==========================\n\tEnter the name of contact to delete:");
        gets(name);
        fp=fopen( "contact.dat", "r" );
        ft=fopen( "temp.dat", "w" );
        while(fscanf(fp,"%s %lld %s %s",phn.name,&phn.m_no,phn.add,phn.email)!=EOF)
        {
            if (strcmp(name,phn.name)==0)
                continue;
            else
                fprintf(ft,"%s %lld %s %s\n",phn.name,phn.m_no,phn.add,phn.email);
        }
        fclose(fp);
        fclose(ft);
        remove( "contact.dat" );
        rename( "temp.dat","contact.dat");
        printf("\n\n------>Successfully Deleted.");
        break;
    default:
        printf( "Invalid choice" );
        Sleep(900);
        goto ff;

    }
fs:
    gotoxy(15,63);
    printf( "Enter the Choice:");
    gotoxy(15,64);
    printf("[1] Main Menu\t\t[0] Exit" );
    gotoxy(15,66);
    scanf( "%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf( "Invalid choice" );
        Sleep(900);
        goto fs;
    }
    return 0;
}
