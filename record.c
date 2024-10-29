#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    char className[20];
    char mobileNumber[15];
};

void addStudent(struct Student *s) {
    FILE *fp = fopen("record.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s->id);
    getchar();

    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter class: ");
    fgets(s->className, sizeof(s->className), stdin);
    s->className[strcspn(s->className, "\n")] = '\0';

    printf("Enter mobile no: ");
    fgets(s->mobileNumber, sizeof(s->mobileNumber), stdin);
    s->mobileNumber[strcspn(s->mobileNumber, "\n")] = '\0';

    fprintf(fp, "%d %s %s %s\n", s->id, s->name, s->className, s->mobileNumber);
    fclose(fp);
}

void displayStudent(struct Student s) {
    printf("Roll no: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Class: %s\n", s.className);
    printf("Mobile: %s\n", s.mobileNumber);
    printf("\n");
}

void getDataStudent(struct Student s[], int *studentCount) {
    FILE *fp = fopen("record.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int size;
    printf("Enter number of student\n");
    scanf("%d",&size);
    *studentCount=size;
    getchar();

    int i = 0;
    while ( i<size && fscanf(fp, "%d %49s %19s %14s\n", &s[i].id, s[i].name, s[i].className, s[i].mobileNumber) == 4 ) 
    {
        printf("Working...\n");
        i++; 
    }
    fclose(fp);
    free(studentCount);
}

void searchByID(struct Student s[], int size) {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < size; i++) {
        if (s[i].id == id) {
            displayStudent(s[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("ID not found!\n");
    }
}

void searchByName(struct Student s[], int size) {
    char name[50];
    int found = 0;
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';   // finds the position of the newline character and replaces it with a null terminator to clean up the input

    for (int i = 0; i < size; i++) {
        if (strcmp(s[i].name, name) == 0) {  // checks if the  name in the current Student struct matches the input name
            displayStudent(s[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Name not found!\n");
    }
}

void searchStudent(struct Student s[], int size) {
    int choice;
    do {
        printf("\n--------------------------\n");
        printf("\n 1. Search by ID");
        printf("\n 2. Search by Name");
        printf("\n 3. Back");
        printf("\n--------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                searchByID(s, size);
                break;
            case 2:
                searchByName(s, size);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid choice! Please try again!\n");
        }
    } while (choice != 3);
}

void deleteByID(struct Student s[], int *size) {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *size; i++) {
        if (s[i].id == id) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                s[j] = s[j + 1];  //it shifts all subsequent elements one position to the left to overwrite the deleted element.
            }
            (*size)--;     //Decreases the size of the array by 1.
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("ID not found!\n");
    }
}

int main() {
    struct Student students[100];
    int studentCount = 0;
    int choice;

    do {
        printf("\n----Student Management----\n");
        printf("\n 1. Add student");
        printf("\n 2. Display students");
        printf("\n 3. Search student");
        printf("\n 4. Delete student");
        printf("\n 5. Read Data of student");
        printf("\n 6. Exit\n");
        printf("\n--------------------------\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input for choice.\n");
            break; // Exit the loop if invalid input
        }
        getchar();

        switch (choice) {
            case 1:
                addStudent(&students[studentCount++]);
                break;
            case 2:
                for (int i = 0; i < studentCount;i++) 
                {
                    displayStudent(students[i]);
                }
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                deleteByID(students, &studentCount);
                break;
            case 5:
                getDataStudent(students,&studentCount);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again!\n");
        }
    } while (choice != 6);

    return 0;
}