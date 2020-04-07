#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define Student struct Stud

int exNo;

void add(FILE * fp); //to add to list
void del(FILE * fp);//to delete from list
void modify(FILE * fp,int x);//to modify a record
void displayList(FILE * fp,int x);//display whole list
void searchRecord(FILE *fp,int x);//find a particular record(For Teachers)
void searchRecordStudent(FILE *fp,int x);//find a particular record(For Students)
void printChar(char ch,int n);//printing a character ch n times
void printHead();//printing head line for each screen
void printMenu();// Prints the main menu header
void main_menu();//MAIN MENU



struct Stud
{
    char name[100];
    char dept[50];
    int id ;
    float marks[8];
    float avg;

};


int main()
{
 FILE * fp;
 Student s;
int option;
char another;
int inp_no;

if((fp=fopen("studentInfo.txt","rb+"))==NULL)
{
    if((fp=fopen("studentInfo.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}

printHead();
printf("\n\n\t\t\t PROGRAMMED BY,");
printf("\n\n\t\t\t HASIB ULLAH & MOHAMMED SHAHRIAR");
printf("\n\n\t\t\t CSE DEPARTMENT\n");
printf("\n\t\t\t press any key to continue...");
getch();

while(1)
{
    printHead();
    printf("\n\t");


    start:
        system("cls");
        printHead();
        main_menu();

    scanf("%d", &inp_no);
    if(inp_no==1){
        system("cls");

        printf("\n\n\t\t\t1. ADD Student");
        printf("\n\n\t\t\t2. DELETE Student");
        printf("\n\n\t\t\t3. MODIFY Student");
        printf("\n\n\t\t\t4. DISPLAY Student LIST");
        printf("\n\n\t\t\t5. Search Record");
        printf("\n\n\t\t\t6. Main Menu");
        printf("\n\n\t\t\t0. EXIT");

        printf("\n\n\t\tEnter Your Option :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 0: return 1;
                    break;
            case 1: add(fp);
                    break;
            case 2: del(fp);
                    break;
            case 3: modify(fp,exNo);
                    break;
            case 4: displayList(fp,exNo);
                    break;
            case 5: searchRecord(fp,exNo);
                    break;
            case 6: goto start;
            default: printf("\n\n\t\tYou Pressed the wrong key");
                      printf("\n\t\tProgram terminated");
                      getch();
                      exit(0);

            }
        }
        else if(inp_no==0){
            exit(0);
        }
        else if(inp_no==2){
            system("cls");

            printf("\n\n\t\t\t1. Check Grades");
            printf("\n\n\t\t\t2. Main Menu");
            printf("\n\n\t\t\t0. EXIT");

            printf("\n\n\t\tEnter Your Option :--> ");
            scanf("%d",&option);

            switch(option){
                case 0: return 0;
                case 1:searchRecordStudent(fp,exNo);
                case 2: main_menu();


            }
        }
    }
    return 1;

}

///----printing character ch at n times ------

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

///-----Printing Head Line of the program -----

void printHead()
{ system("cls");

printf("\n\n\n");
printChar('=',21);
printf("[STUDENT TEACHER COMMUNICATION CENTER]");
printChar('=',21);
printf("\n\n");
printChar('-',80);
}

/// ==========ADDING MAIN MENU HEADER====================
void printMenu(){
    printf("\n\n\t");
   // printChar('=',16);
    printf("\t\t\t MAIN MENU");
    //printChar('=',16);
    printf("\n");

    printf("\t\t\t\t-----------");
    }
/// ===========ADDING MAIN MENU==========================
void main_menu(){
    printMenu();
    printf("\n\n\t\t\t1. Are You A Teacher?");
    printf("\n\n\t\t\t2. Are You A Student?");
    printf("\n\n\t\t\tPress '1' if you are a Teacher.");
    printf("\n\n\t\t\tPress '2' if you are a Student.");
    printf("\n\n\t\t\tPress '0' To EXIT\n\n\t\t\t:");

}
///==========ADDING NEW RECORD==========================

void add(FILE * fp)
{
printHead();

char another='y';
Student s;
int i;
float avg;

fseek(fp,0,SEEK_END);
    printf("\n\n\t\tHow Many Exams Did you take :\t");
    scanf("%d", &exNo);
while(another=='y'||another=='Y')
{

    printf("\n\n\t\tEnter Full Name of Student :\t");
    fflush(stdin);
    fgets(s.name,100,stdin); //fgets takes an extra \n character as input
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter Department : \t");
    fflush(stdin);
    fgets(s.dept,50,stdin);
    s.dept[strlen(s.dept)-1]='\0';

    printf("\n\n\t\tEnter ID number \t");
    scanf("%d",&s.id);

    int i=1,temp_ex_n;

    temp_ex_n = exNo;


    for(i=0,avg=0;i<exNo;i++)
    {
         printf("\n\n\tEnter  Marks for exam no: #%d \n\t",i+1);
        scanf("%f",&s.marks[i]);
        avg+=s.marks[i];

    }

    avg/=temp_ex_n;
    s.avg=avg;

    fwrite(&s,sizeof(s),1,fp);

    printf("\n\n\t\tWant to enter another student info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}


///===================DELETING A RECORD FROM LIST ============
void del(FILE * fp)
{
 printHead();

Student s;
int flag=0,tempRoll,siz=sizeof(s);
FILE *ft;

if((ft=fopen("temp.txt","wb+"))==NULL)
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tEnter ID number of Student to Delete the Record");
printf("\n\n\t\t\ID No. : ");
scanf("%d",&tempRoll);

rewind(fp);


while((fread(&s,siz,1,fp))==1)
{
    if(s.id==tempRoll)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.dept,s.id);
    continue;
    }

    fwrite(&s,siz,1,ft);
}


fclose(fp);
fclose(ft);

remove("studentInfo.txt");
rename("temp.txt","studentInfo.txt");

if((fp=fopen("studentInfo.txt","rb+"))==NULL)
{
    printf("ERROR");
    return  NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}


///===========MODIFY A RECORD ===========================

void modify(FILE * fp,int x)
{
printHead();

Student s;
int i,flag=0,tempRoll,siz=sizeof(s);
float avg;


printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.id==tempRoll)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");

    printf("\n\n\t\tEnter Full Name of Student: \t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter Department: \t");
    fflush(stdin);
    fgets(s.dept,50,stdin);
    s.dept[strlen(s.dept)-1]='\0';

    printf("\n\n\t\tEnter ID : \t");
    scanf("%d",&s.id);




    for(i=0,avg=0;i<x;i++)
        {
            printf("\n\n\tEnter New Marks exam #%d : \t",i+1);
            scanf("%f",&s.marks[i]);
            avg+=s.marks[i];

        }
        avg=avg/x;
        s.avg=avg;


    fwrite(&s,sizeof(s),1,fp);
}

else printf("\n\n\t!!!! ERROR !!!! \n\n\tRECORD NOT FOUND");

printf("\n\n\t");
system("pause");

}

///====================DISPLAY THE LIST =================
void displayList(FILE * fp,int x)
{   printHead();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\n\tNAME : %s",s.name);
        printf("\n\n\t\DEPARTMENT : %s",s.dept);
        printf("\n\n\t\ID : %d",s.id);
      //  printf("\n\n\tSGPA: ");

        for(i=0;i<x;i++)
            printf("\n\n\t\Marks for Exam NO #%d : %.2f |\n",i+1,s.marks[i]);
            printf("\n\n\t\Average : %.2f\n\t",s.avg);
            printChar('-',65);
    }
    s.marks[0];
    printf("\n\n\n\t");
     printChar('#',65);
    printf("\n\n\t");
    system("pause");
}
/// ========================SEARCHING RECORD FOR TEACHERS TO SEARCH==========================
void searchRecord(FILE *fp,int x)
{printHead();

int tempRoll,flag,siz,i;
Student s;
char another='y';
int range = exNo;

siz=sizeof(s);


while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID Number: ");
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.id==tempRoll)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tDepartment : %s",s.dept);
        printf("\n\n\t\tID : %d",s.id);
        //printf("\n\n\t\tSGPA: ");

        for(i=0;i<x;i++)

            printf("\n\n\t\t| Marks for exam #%d:  %.2f |",i+1,s.marks[i]);
            printf("\n\n\t\t Average Marks : %.2f\n\t",s.avg);

            printChar('-',65);


}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}
///====================SEARCH RECORD FOR THE STUDENTS TO SEARCH===========================
void searchRecordStudent(FILE *fp,int x)
{
    printHead();

    int tempRoll,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
    printf("\n\n\tEnter Your ID Number to check your marks : ");
    scanf("%d",&tempRoll);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.id==tempRoll)
            {flag=1;
            break;
            }
    }

    if(flag==1)
        {
        printf("\n\t\tNAME : %s",s.name);
            printf("\n\n\t\tDepartment : %s",s.dept);
            printf("\n\n\t\tID : %d\n",s.id);
           // printf("\n\n\tSGPA: ");

            for(i=0;i<x;i++)

                printf("\n\t\tMarks For Exam #%d : %.2f \n",i+1,s.marks[i]);
                printf("\n\n\t\tAverage : %.2f\n\t",s.avg);
                printChar('-',65);


    }
    else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


    printf("\n\n\t\tWant to enter another search (Y/N)");
    fflush(stdin);
    another=getchar();
}
}

