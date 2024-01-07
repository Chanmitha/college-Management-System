#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char firstName[50];
    char course[50];
};

struct Student students[100];
int count = 0;

void addStudent() {
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].rollNumber);
    printf("Enter First Name: ");
    scanf("%s", students[count].firstName);
    printf("Enter Course: ");
    scanf("%s", students[count].course);
    count++;
}

void findStudentByRollNumber() {
    int rollNumber;
    printf("Enter Roll Number to find: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Found!\n");
            printf("Roll Number: %d, Name: %s, Course: %s\n", students[i].rollNumber, students[i].firstName, students[i].course);
            return;
        }
    }

    printf("Student with Roll Number %d not found!\n", rollNumber);
}

void findStudentByFirstName() {
    char firstName[50];
    printf("Enter First Name to find: ");
    scanf("%s", firstName);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].firstName, firstName) == 0) {
            printf("Student Found!\n");
            printf("Roll Number: %d, Name: %s, Course: %s\n", students[i].rollNumber, students[i].firstName, students[i].course);
            return;
        }
    }

    printf("Student with First Name %s not found!\n", firstName);
}

void findStudentsByCourse() {
    char course[50];
    printf("Enter Course to find students: ");
    scanf("%s", course);

    printf("Students in Course %s:\n", course);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].course, course) == 0) {
            printf("Roll Number: %d, Name: %s\n", students[i].rollNumber, students[i].firstName);
        }
    }
}

void displayStudentCount() {
    printf("Total Students: %d\n", count);
}

void deleteStudent() {
    int rollNumber;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student with Roll Number %d deleted!\n", rollNumber);
            return;
        }
    }

    printf("Student with Roll Number %d not found!\n", rollNumber);
}

void updateStudent() {
    int rollNumber;
    printf("Enter Roll Number to update: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new First Name: ");
            scanf("%s", students[i].firstName);
            printf("Enter new Course: ");
            scanf("%s", students[i].course);
            printf("Student with Roll Number %d updated!\n", rollNumber);
            return;
        }
    }

    printf("Student with Roll Number %d not found!\n", rollNumber);
}

int main() {
    int choice;

    do {
        printf("\nCollege Management System Menu:\n");
        printf("1. Add Student Details\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Find Student by First Name\n");
        printf("4. Find Students in a Course\n");
        printf("5. Display Count of Students\n");
        printf("6. Delete a Student\n");
        printf("7. Update Student Details\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                findStudentByRollNumber();
                break;
            case 3:
                findStudentByFirstName();
                break;
            case 4:
                findStudentsByCourse();
                break;
            case 5:
                displayStudentCount();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                updateStudent();
                break;
            case 0:
                printf("Exiting College Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

