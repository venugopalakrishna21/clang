#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent() {
    if (count < MAX_STUDENTS) {
        printf("Enter Student ID: ");
        scanf("%d", &students[count].id);
        printf("Enter Student Name: ");
        scanf("%s", students[count].name);
        printf("Enter Marks: ");
        scanf("%f", &students[count].marks);
        count++;
        printf("Student added successfully!\n");
    } else {
        printf("Student list is full!\n");
    }
}

void displayStudents() {
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Record Found: ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nStudent Record Management\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
