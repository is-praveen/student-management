#include<stdio.h>
#include <stdlib.h> // Include this for atoi
#include<string.h>

struct Student
{
    int id;
    char name[50];
    char className[20];
    char mobileNumber[15];

};

void addStudent(struct Student *s) 
{ 
    char ch[4]; 
    FILE *fp = fopen("record.txt", "a+"); 
    if (fp == NULL) 
    { 
        printf("Error opening file!\n"); 
        return; 
        } 
        printf("Enter ID: "); 
        scanf("%d", &s->id); 
        sprintf(ch, "%d ", s->id); 
        fputs(ch, fp); 
        getchar(); // consume newline left by scanf 

        printf("Enter name: "); 
        fgets(s->name, sizeof(s->name), stdin); 
        s->name[strlen(s->name) - 1] = '\0'; 
        fputs(strcat(s->name, " "), fp); 

        printf("Enter class: "); 
        fgets(s->className, sizeof(s->className), stdin); 
        s->className[strlen(s->className) - 1] = '\0'; 
        fputs(strcat(s->className, " "), fp); 

        printf("Enter mobile no: "); 
        fgets(s->mobileNumber, sizeof(s->mobileNumber), stdin); 
        s->mobileNumber[strlen(s->mobileNumber) - 1] = '\0'; 
        fputs(strcat(s->mobileNumber, "\n"), fp); 

        fclose(fp);
}
void displayStudent(struct Student s)
{
        printf("Roll no: %d\n",s.id);
        printf("Name: %s\n",s.name);
        printf("Class: %s\n",s.className);
        printf("Mobile: %s\n",s.mobileNumber);

}
void getDataStudent(struct Student s[], int size) 
{ 
    FILE *fp = fopen("record.txt", "r"); 
    if (fp == NULL) 
    { 
        printf("Error opening file!\n"); 
        return;
    } 
    char ch; 
    int i = 0, j = 0, count = 0; 
    char str[50]; 
    while ((ch = fgetc(fp)) != EOF) 
    { 
        if (ch == '\t' || ch == '\n') 
        { 
            str[i] = '\0'; // Null-terminate the string 
            if (count == 0) 
            { 
                
                s[j].id = atoi(str); 
                printf("%d\t",s[j].id);
            } 
            else if (count == 1) 
            { 
                strcpy(s[j].name, str);
                printf("%s\t",s[j].name); 
            } 
            else if (count == 2) 
            { 
                strcpy(s[j].className, str); 
                printf("%s\t",s[j].className);
            } 
            else if (count == 3) 
            { 
                strcpy(s[j].mobileNumber, str); 
                printf("%s\t",s[j].mobileNumber);
            } 
            i = 0; // Reset index for next field 
            count++; 
            if (ch == '\n') 
            { 
                count = 0; // Reset count for next student 
                j++; // Move to the next student } 
                continue; // Proceed to read the next character 
            } 
            str[i++]=ch; 
        } 
        fclose(fp); 
    }
}
void searchByID(struct Student t[], int size)
{
    int i;
    int id;
    int found=0;
    printf("Enter you want search id: ");
    scanf("%d",&id);
    getchar();
    for(i=0;i<size;i++)
    {
        if(t[i].id == id)   
        {
            displayStudent(t[i]);
            found=1;
        }
    }
    if(!found)
        printf("ID not found!\n");
}
void searchByName(struct Student t[], int size)
{
    int i,j;
    char name[50];
    int found=0;
    printf("Enter you want search name: ");
    getchar();
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]='\0';

    for(i=0;i<size;i++)
    {
        /*
        for(j=0;j<name[j];j++)
        {
            if (t[i]->name[j]!=name[j]) 
            { 
                break;
            }
        }
        if(j==strlen(name))
        {
            displayStudent(*t[i]); 
            found=1;
        }
        */
        if (strcmp(t[i].name, name) == 0) 
        { 
            printf("Working ");
            displayStudent(t[i]); 
            found = 1; 
        }
    }
    if(!found)
        printf("Name not found!\n");
}
void searchStudent(struct Student p[], int size)
{
    int choice=0;
    do{
        printf("\n--------------------------\n");
        printf("\n  1. Search by ID");
        printf("\n  2. Search by Name");
        printf("\n  3. Back");
        printf("\n--------------------------\n");
        printf("\nEnter your choice: \n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                searchByID(p, size);
                break;
            case 2:
                searchByName(p, size);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid choice! Please try again!\n");
        }
    }while(choice!=3);
}
void deleteByID(struct Student p[], int size)
{

}
int main()
{
    struct Student students[100]={0};
    int studentCount=0;
    int choice=0;
    do
    {
        printf("\n----Student Management----\n");
        printf("\n  1. Add student");
        printf("\n  2. Display student");
        printf("\n  3. Search student");
        printf("\n  4. Delete student");
        printf("\n  5. Exit");
        printf("\n  6. read file\n");
        printf("\n--------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                // add student data;
                addStudent(&students[studentCount++]);
                break;
            case 2: 
                for (int i = 0; i < studentCount; i++) {
                    displayStudent(students[i]);
                }
                // display student data;
                break;
            case 3: 
                searchStudent(students, studentCount);
                // search student;
                break;
            case 4:
                deleteByID(students,studentCount);
                // delete student
                break;
            case 5:
                printf("\nExiting...\n");
                
                break;
            case 6:
                getDataStudent(students,100);
                break;
            default:
                printf("\nYOU ENTERED INVALID CHOICE.\n");
        }
    }while(choice!=5);
    return 0;
}