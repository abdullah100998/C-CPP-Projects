/**.................................Bismillahir-Rahamanirahim..................................**/

/*
*(c) 2020 Team : Fantastic 4
*[1]Md.Mahfuzur Rahman      || Id:193-15-13416 ||
*[2]Md.Abdullah Ibna Harun  || Id:193-15-13426 ||
*[3]Md.Mahade Hassan Forhad || Id:193-15-13355 ||
*[4]Md.Abidur Rahman Khan   || Id:193-15-13374 ||
*/

/**................ Headers ................**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

//Function Prototype
void registersys();
void login();
void page_1();
void aboutinfo();
void mainsystem();
void logout();
void addrecord(int k);
void viewrecord();
void searchrecord(int k);
void modifyrecord(int k);
void deleterecord(int k);
void printfile(int k);
void insertfromfile();
void page_2();

//this is login structure part
struct login
{
    char fname[20];
    char lname[20];
    char username[20];
    char password[32];
    char email[100];
};

//Linked list
typedef struct Node
{
    char name[50];
    char email[50];
    char mobile[20];
    struct Node *next;
} node;

node *head = NULL;
int count=1;

//main function
int main()
{
    printf("+++++++++++++++++Hello world!+++++++++++++++++++\n");
    mainsystem();
    return 0;
}

//insert data from text file
void insertfromfile()
{
    head = NULL;

    FILE *fp;
    fp = fopen("info.txt","r+");
    char name[50];
    char em[50];
    char num[25];
    while(fscanf(fp,"%s \t\t %s \t\t %s\n",name,em,num)!=EOF)
    {
        node * newdata = (node*)malloc(sizeof(node));
        node * current;
        strcpy(newdata->name,name);
        strcpy(newdata->email,em);
        strcpy(newdata->mobile,num);
        newdata->next = NULL;
        if(head==NULL)
        {
            head = newdata;
        }
        else
        {
            current = head;
            while(current->next!=NULL)
            {
                current = current->next;
            }
            current->next = newdata;
        }
    }
    fclose(fp);
}


//After login this is front page
void page_1()
{
    char ch;

    system("cls && color E");
    printf("\n\n\n\t>>>> Welcome to Phone Book Management system");
    printf("\n\n\t=====> [01] Add Record Phone Book");
    printf("\n\n\t=====> [02] View Phone Book List");
    printf("\n\n\t=====> [03] Search in Phone Book Record");
    printf("\n\n\t=====> [04] Modify Phone Book Record");
    printf("\n\n\t=====> [05] Delete Phone Book Record");
    printf("\n\n\t=====> [06] Delete All Phone Book Record");
    printf("\n\n\t=====> [07] Logout.");
    printf("\n\n\t=========>>Enter Your Choice :  ");
    ch=getche();
    switch(ch)
    {
    case '1':
        system("cls");
        addrecord(1);
        break;
    case '2':
        system("cls");
        viewrecord(1);
        break;
    case '3':
        system("cls");
        searchrecord(1);
        break;
    case '4':
        system("cls");
        modifyrecord(1);
        break;
    case '5':
        system("cls");
        deleterecord(1);
        break;
    case '6':
        system("cls");
        printfile(6);
        break;
    case '7':
        system("cls");
        logout();
        break;
    default :
        system("cls && color 4");
        printf("\a");
        printf("\n\n\tInvalid keyword..");
        printf("\n\nPress any key to go back,.....");
        getch();
        page_1();
        break;
    }

}

//this is operation mood page
void page_2()
{
    char ch;
    printf("\n\n\n\t\t>>>> Operation Mood\n");
    printf("\n\n\t=====> [01] Add Record Phone Book");
    printf("\n\n\t=====> [02] View Phone Book List");
    printf("\n\n\t=====> [03] Search in Phone Book Record");
    printf("\n\n\t=====> [04] Modify Phone Book Record");
    printf("\n\n\t=====> [05] Delete Phone Book Record");
    printf("\n\n\t=====> Press any key to back...");
    printf("\n\n\t=========>>Enter Your Choice :  ");
    ch=getch();
    switch(ch)
    {
    case '1':
        system("cls");
        addrecord(2);
        break;
    case '2':
        system("cls");
        viewrecord(2);
        break;
    case '3':
        system("cls");
        searchrecord(2);
        break;
    case '4':
        system("cls");
        modifyrecord(2);
        break;
    case '5':
        system("cls");
        deleterecord(2);
        break;
    default :
        printf("\a");
        page_1();
        break;
    }

}

//delete record function
void deleterecord(int k)
{
    system("cls");
    printf("\n\n\t\t::::: Delete/Remove Operation :::::\n");
    system("color D");
    printf("\n########  All Contact :\n\n");
    printf("**************************************************************************************************\n");
    printf("No . \t\t Name      \t\t\t Email    \t\t\t Mobile\n");
    printf("=================================================================================================\n");

    FILE *fpd;
    fpd = fopen("info.txt","r");
    char namef[50];
    char emf[50];
    char numf[22];
    int fi=1;
    while(fscanf(fpd,"%s \t\t %s \t\t %s\n",namef,emf,numf)!=EOF)
    {
        printf("%-5d \t  %-20s \t\t %-25s  \t\t %-15s\n",fi,namef,emf,numf);
        fi++;
    }
    fclose(fpd);
    printf("\n\n\t Press any key to start operation...");
    getch();

    printf("\n\n\tPress 1: For Delete By Name");
    printf("\n\tPress 2: For delete By Phone mobile ");
    printf("\n\tPress 0: For go back\n\tChoice : ");
    char choice;
    choice = getch();
    printf("\n");
    char sea[100];
    char numb[25];

    node *previous=NULL,*temp=NULL;

    switch(choice)
    {
    case '1':
        printf("\n\n\tEnter Name You want to Delete : ");
        scanf(" %[^\n]s",sea);
        insertfromfile();
        temp=head;
        if((strcmp(head->name,sea)==0))
        {
            head=head->next;
            free(temp);
            printfile(2);
            printf("\n\n\n\tData Deleted successfully !!\n");
        }
        else
        {
            while(temp != NULL && (strcmp(temp->name,sea)!=0))
            {
                previous = temp;
                temp = temp -> next;
            }
            if(temp == NULL)
            {
                printf("\n\t%s Does not Exist in the List\n\n ",sea);
            }
            else
            {
                previous -> next = temp -> next;
                free(temp);
                printfile(2);
                printf("\n\n\n\tData Deleted successfully !!\n");
            }
        }
        break;
    case '2':
        insertfromfile();
        temp=head;
        printf("\n\n\tEnter Phone mobile You want to Delete : ");
        scanf(" %[^\n]s",numb);
        if((strcmp(head->mobile,numb)==0))
        {
            head=head->next;
            free(temp);
            printfile(2);
            printf("\n\n\n\tData Deleted successfully !!\n");
        }
        else
        {
            while(temp != NULL && (strcmp(temp->mobile,numb)!=0))
            {
                previous = temp;
                temp = temp -> next;
            }
            if(temp == NULL)
            {
                printf("\n\t%s Does not Exist in the List\n\n ",numb);
            }
            else
            {
                previous -> next = temp -> next;
                free(temp);
                printfile(2);
                printf("\n\n\n\tData Deleted successfully !!\n");
            }
        }
        break;
    case '0':
        if(k==1)
        {
            system("cls");
            page_1();
        }
        else if(k==2)
        {
            system("cls");
            page_2();
        }
        break;
    default :
        printf("\n\n\tInvalid Key....\n\n\t operation exit....");
        break;
    }
    printf("\n\n\tPress any key to go back .........");
    getch();
    if(k==1)
    {
        system("cls");
        page_1();
    }
    else if(k==2)
    {
        system("cls");
        page_2();
    }
}


//search record function
void searchrecord(int k)
{
    insertfromfile();
    system("color C");
    printf("\n\n\t\t::::: Search Operation :::::");
    printf("\n\tPress 1: For Search By Name");
    printf("\n\tPress 2: For search By Phone mobile");
    printf("\n\tPress 0: For go back \n\tChoice : ");
    int choice ;
    choice = getche();
    printf("\n");
    char sea[100];
    char name[50];
    char em[50];
    char num[25];
    char numb[25];
    int pos=1;
    node *temp=head;
    int c1=1;

    switch(choice)
    {
    case '1':
        printf("\n\n\tEnter Name You want to Search : ");
        scanf(" %[^\n]s",sea);
        while(temp!=NULL)
        {
            if(strcmp(temp->name,sea)==0)
            {
                strcpy(num,temp->mobile);
                strcpy(name,temp->name);
                strcpy(em,temp->email);
                c1++;
                break;
            }
            else
            {
                temp=temp->next;
                pos++;
            }
        }
        if(c1>1)
        {
            printf("\n\n\tContact Details Found\n");
            printf("\t\tserial   : %d\n",pos);
            printf("\t\tName     : %s\n",name);
            printf("\t\tEmail    : %s\n",em);
            printf("\t\tPhone NO.: %s",num);
        }
        else if(c1==1)
        {
            printf("\a\n\t\t\tData does not exist in the List \n");
        }
        break;
    case '2':
        c1=1;
        printf("\n\n\tEnter Phone mobile You want to Search : ");
        scanf(" %[^\n]s",numb);
        while(temp!=NULL)
        {
            if(strcmp(temp->mobile,numb)==0)
            {
                strcpy(num,temp->mobile);
                strcpy(name,temp->name);
                strcpy(em,temp->email);
                c1++;
                break;
            }
            else
            {
                temp=temp->next;
                pos++;
            }
        }
        if(c1>1)
        {
            printf("\n\n\tContact Details Found\n");
            printf("\t\tserial   : %d\n",pos);
            printf("\t\tName     : %s\n",name);
            printf("\t\tEmail    : %s\n",em);
            printf("\t\tPhone NO.: %s",num);
        }
        else if(c1==1)
        {
            printf("\a\n\t\t\tData does not exist in the List \n");
        }
        break;
    case '0':
        if(k==1)
        {
            system("cls");
            page_1();
        }
        else if(k==2)
        {
            system("cls");
            page_2();
        }
        break;
    default:
        printf("\n\n\tInvalid Key....\n\n\t operation exit....");
        break;
    }
    printf("\n\nPress any key to go back .........");
    getch();
    if(k==1)
    {
        system("cls");
        page_1();
    }
    else if(k==2)
    {
        system("cls");
        page_2();
    }

}

//Logout function
void logout()
{
    system("cls");
    printf("\n\n\n\t\t\t Log out successfully !.....\n");
    printf("\n\n\n\t\t\tThanks for using our Application");
    printf("\n\t\t\tRemember,You are the valuable client of our Comapnay");
    printf("\n\n\n\t\t\t Any key to continue.........");

    getch();
    mainsystem();
}

//record output function
void viewrecord()
{
    FILE *fptr;
    fptr=fopen("info.txt","r");
    if(fptr==NULL)
    {
        system("color 4");
        printf("\a\aThere is an error occurred\n\n\n ");
        printf("Go To Entry Menu to create File");
        printf("\n\n\n Program is closing please contact....");
        getch();
        aboutinfo();
        exit(0);
    }
    fclose(fptr);

    system("color 7");
    printf("\n########  All Contact :\n\n");
    printf("**************************************************************************************************\n");
    printf("No . \t\t Name      \t\t\t Email    \t\t\t Mobile\n");
    printf("=================================================================================================\n");

    FILE *fp;
    fp = fopen("info.txt","r");
    char name[50];
    char em[50];
    char num[25];
    int i=1;
    while(fscanf(fp,"%s \t\t %s \t\t %s\n",name,em,num)!=EOF)
    {
        printf("%-5d \t  %-20s \t\t %-25s  \t\t %-15s\n",i,name,em,num);
        i++;
    }
    printf("\n\tPress any Key to go operation mood .....");
    fclose(fp);
    getch();

    page_2();

}

//data print on file function
void printfile(int k)
{
    //for add
    if(k==1)
    {
        FILE *fp;
        fp = fopen("info.txt","a+");
        node *temp = head;
        while(temp!=NULL)
        {
            fprintf(fp,"%s \t\t %s \t\t %s\n",temp->name,temp->email,temp->mobile);
            temp = temp->next;
        }
        fclose(fp);
    }
    //for update
    else if(k==2)
    {
        FILE *fp;
        fp = fopen("info.txt","w");
        node *temp = head;
        while(temp!=NULL)
        {
            fprintf(fp,"%s \t\t %s \t\t %s\n",temp->name,temp->email,temp->mobile);
            temp = temp->next;
        }
        fclose(fp);
    }
    //for delete
    else if(k==6)
    {
        FILE *fp;
        fp = fopen("info.txt","w");
        fclose(fp);
        system("color F && cls");
        printf("\n\t\a\t\n\t::::::::::::::All data deleted:::::::::::::\n");
        printf("\n\n\t\tPress any key to continue................");
        getch();
        system("cls && color 5");
        page_1();
    }
}

//add data record in linked list
void addrecord(int k)
{
    system("CLS");
    int i,siz;
    head = NULL;
    printf("\n\t\t::::: Data Insert Operation ::::::\n");
    printf("\n\tHow many mobile number you want to add: ");
    scanf("%d",&siz);
    for(i=0; i<siz; i++)
    {
        node *newdata = (node*)malloc(sizeof(node));
        node *current;
        printf("\n%d ) Input Name     : ",i+1);
        scanf(" %[^\n]s",&newdata->name);
        printf("\nInput Email         : ");
        scanf(" %[^\n]s",&newdata->email);
        printf("\nInput Mobile mobile : ");
        scanf(" %[^\n]s",&newdata->mobile);
        newdata->next=NULL;
        if(head==NULL)
        {
            head = newdata;
        }
        else
        {
            current = head;
            while(current->next!=NULL)
            {
                current = current->next;
            }
            current->next = newdata;
        }
        count++;
    }
    printfile(1);
    printf("\n==Data insert successfully==\n\n");
    printf("\n\tAny key to continue .....");
    getch();
    if(k==1)
        page_1();
    else if(k==2)
        page_2();
}


//Data modify / update
void modifyrecord(int k)
{
    system("CLS && COLOR 6");
    printf("\n\n\t\t::::: Modify/Update Operation :::::\n");
    printf("\n########  All Contact :\n\n");
    printf("**************************************************************************************************\n");
    printf("No . \t\t Name      \t\t\t Email    \t\t\t Mobile\n");
    printf("=================================================================================================\n");

    FILE *fpd;
    fpd = fopen("info.txt","r");
    char namef[50];
    char emf[50];
    char numf[22];
    int fi=1;
    while(fscanf(fpd,"%s \t\t %s \t\t %s\n",namef,emf,numf)!=EOF)
    {
        printf("%-5d \t  %-20s \t\t %-25s  \t\t %-15s\n",fi,namef,emf,numf);
        fi++;
    }
    int total = fi;
    fclose(fpd);
    printf("\n\n\t Press any key to start operation...");
    getch();

    int usp;
    printf("\n\n\tWhich No. Data You want to Modify : ");
    scanf("%d",&usp);

    if(usp<1 || usp>=total)
    {
        printf("\n\n\a\tInvalid position !!! Sorry this operation unsuccessful\n");
        printf("\n\tPress any key to get back ....");
        getch();
        if(k==1)
        {
            system("cls");
            page_1();
        }
        else
        {
            system("cls");
            page_2();
        }
    }
    else if(usp>=1 && usp<=total)
    {
        insertfromfile();
        node *prev, *updata = head;
        int pos = 0;
        while(pos!=usp)
        {
            prev = updata;
            updata=updata->next;
            pos++;
        }
        printf("\n\n\tPosition valid-->");
        printf("\n\tPress 1: Modify  Name");
        printf("\n\tPress 2: Modify  Email");
        printf("\n\tPress 3: Modify  Phone mobile ");
        printf("\n\tPress 4: Modify All record on that position");
        printf("\n\tPress 0: For go back\n\tChoice : ");
        char choice;
        choice = getch();
        printf("\n");
        char name[50];
        char numb[20];
        char mail[50];

        switch(choice)
        {
        case '1':
            printf("\n\n\t %d No. Dataset -> Enter Name : ",usp);
            scanf(" %[^\n]s",name);
            strcpy(prev->name,name);
            printfile(2);
            printf("\n\n\tData update successfully!\n");
            break;

        case'2':
                printf("\n\n\t %d No. Dataset -> Enter Email : ",usp);
            scanf(" %[^\n]s",mail);
            strcpy(prev->email,mail);
            printfile(2);
            printf("\n\n\tData update successfully!\n");
            break;

        case'3':
                printf("\n\n\t %d No. Dataset -> Enter Mobile : ",usp);
            scanf(" %[^\n]s",numb);
            strcpy(prev->mobile,numb);
            printfile(2);
            printf("\n\n\tData update successfully!\n");
            break;

        case'4':
                printf("\n\t %d No. Dataset -> Enter Name : ",usp);
            scanf(" %[^\n]s",name);
            strcpy(prev->name,name);
            printf("\n\t %d No. Dataset -> Enter Email : ",usp);
            scanf(" %[^\n]s",mail);
            strcpy(prev->email,mail);
            printf("\n\t %d No. Dataset -> Enter Mobile : ",usp);
            scanf(" %[^\n]s",numb);
            strcpy(prev->mobile,numb);
            printfile(2);
            printf("\n\n\tData update successfully!\n");
            break;

        case'0':
                if(k==1)
                {
                    system("cls");
                    page_1();
                }
                else if(k==2)
                {
                    system("cls");
                    page_2();
                }
            break;
        default :
            system("Color 4");
            printf("\n\n\tInvalid Key....\n\n\t operation exit....\n");
            break;
        }
    }
    printf("\n\n\tPress Any Key to continue..... ");
    getch();
    if(k==1)
    {
        system("cls");
        page_1();
    }
    else if(k==2)
    {
        system("cls");
        page_2();
    }

}

//user login function
void login()
{
    FILE *log=fopen("project.txt","r");
    struct login l;

    printf("\n\t\t\t=======================[ LOG IN ]======================\n");

    char line[500],fName[100],lName[100],email[100],username[200],password[20];
    system("color 7");
    printf("\n\t\t\t:::::::::: UserID   : ");
    scanf(" %[^\n]s",&username);
    system("color 8");
    printf("\n\t\t\t:::::::::: Password : ");
    scanf(" %[^\n]s",&password);

    int flag=0;

    while(fgets(line, sizeof line, log)!=NULL)
    {
        sscanf(line,"%s\t%s\t\t%s\t\t%s\t%s",fName,lName,email,l.username,l.password);

        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            system("cls && color 2");
            printf("\n\t\t>> ***successfully log in\n");
            flag=1;
            printf("\n\n\n\t\t>>Do not forget to wash your hand before continue :D");
            printf("\n\t\t>>Don't Forget, You are the valueable client of our company :D");
            printf("\n\n\t\t>> ***Press any key to continue.....");
            getch();
            system("cls");
            page_1();
        }
    }

    if(flag==0)
    {
        system("color 4");
        int k;
        printf("\a\n\n\t\t log in failed\n");
        printf("\a\n\n\t\t Press 1 for homepage..\n");
        printf("\n\t\t or press any key to try again...");
        k = getch();
        switch(k)
        {
        case '1':
            mainsystem();
            break;
        default :
            system("cls");
            login();
            break;
        }

    }

    fclose(log);
}

//user registration function
void registersys()
{
    printf("\n\t\t\t=======================[ User Registration ]======================\n");

    FILE *log=fopen("project.txt","a+");
    struct login l;

    printf("\n\t\t\t======> Enter your first name : ");
    scanf(" %[^\n]s",&l.fname);
    printf("\n\t\t\t======> Enter your last name  : ");
    scanf(" %[^\n]s",&l.lname);
    printf("\n\t\t\t======> Enter Your email      : ");
    scanf(" %[^\n]s",&l.email);
    printf("\n\t\t\t======> Enter your user name  : ");
    scanf(" %[^\n]s",&l.username);
    printf("\n\t\t\t======> Enter your password   : ");
    scanf(" %[^\n]s",&l.password);

    fprintf(log,"%s\t%s\t\t%s\t%s\t%s\n",l.fname,l.lname,l.email,l.username,l.password);

    fclose(log);

    printf("\n\n\t\tRegistration Successful :D\n\n");
    printf("\n\t\t>>Do not forget to eat vegetables & wear safty mask:D");
    printf("\n\t\t>>Do not forget to wash your hand before continue :D");
    printf("\n\t\t>>After All, You are the valueable client of our company :D");
    printf("\n\n\t press any key to continue .........");
    getch();

    system("cls");

    login();
}


// Developer information
void aboutinfo()
{
    int n;
    system("cls");
    system("color A");
    printf("\n\n\n\n\n\n");
    printf("\t\t===============================================================\n");
    printf("\t\t**------------Welcome to Phone book Application--------------**\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t**    Meet our Back End & Font End Developers:               **\n");
    printf("\t\t**                                                           **\n");
    system("color B");
    printf("\t\t**       [1]Md.Mahfuzur Rahman      || Id:193-15-13416       **\n");
    system("color E");
    printf("\t\t**       [2]Md.Abdullah Ibna Harun  || Id:193-15-13426       **\n");
    system("color D");
    printf("\t\t**       [3]Md.Abidur Rahman Khan   || Id:193-15-13374       **\n");
    system("color 8");
    printf("\t\t**       [4]Md.Mahade Hassan Forhad || Id:193-15-13355       **\n");
    printf("\t\t**                                                           **\n");
    system("color 7");
    printf("\t\t**       |||>>> Thank you for using our software <<<|||      **\n");
    system("color 6");
    printf("\t\t**                                                           **\n");
    system("color 4");
    printf("\t\t**     (C)2020 DS Project  Group:1  All Rights Reserved      **\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t**                                                           **\n");
    system("color A");
    printf("\t\t**                Press any key for Main Menu!!...           **\n");
    printf("\t\t**                Press [0] for Exit!!...                    **\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t===============================================================\n");
    system("color A");
    printf("\t\t\n\n=========>>Enter Your Choice :");
    n=getche();
    switch (n)
    {
    case '0':
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        mainsystem();
        break;
    }
}


//front UI panel
void mainsystem()
{
    int n;
    system("cls");
    system("color A");
    printf("\n\n\n\n\n\n");
    printf("\t\t*************************************************************\n");
    printf("\t\t**------------Welcome to Phone book Application------------**\n");
    printf("\t\t**                                                         **\n");
    printf("\t\t**                                                         **\n");
    system("color B");
    printf("\t\t**             [1] Login user                              **\n");
    system("color E");
    printf("\t\t**             [2] Register User                           **\n");
    system("color 8");
    printf("\t\t**             [3] Go to Developer option                  **\n");
    system("color 6");
    printf("\t\t**             [0] EXIT!                                   **\n");
    system("color 4");
    printf("\t\t**                                                         **\n");
    system("color A");
    printf("\t\t**             STAY HOME || STAY SAFE                      **\n");
    printf("\t\t**                                                         **\n");
    printf("\t\t*************************************************************\n");
    system("color B");
    printf("\t\t\n\n=========>>Enter Your Choise : ");

    n=getch();

    switch (n)
    {
    case '1':
        system("cls");
        login();
        break;
    case '2':
        system("cls");
        registersys();
        break;
    case '0':
        system("cls");
        exit(0);
        break;
    case '3':
        system("cls");
        aboutinfo();
        break;
    default :
        system("cls");
        mainsystem();
        break;
    }

}
