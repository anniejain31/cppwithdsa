#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Linked List Structure
struct Student {
    int student_id;
    char name[50];
    float grade;
    struct Student* next;
};

// Global variable to keep track of the head of the linked list
struct Student* head = NULL;

// Function to add a student to the linked list
void addStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed. Cannot add student.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &newStudent->student_id);

    // Check for duplicate student ID
    struct Student* current = head;
    while (current != NULL) {
        if (current->student_id == newStudent->student_id) {
            printf("A student with the same ID already exists. Cannot add duplicate IDs.\n");
            free(newStudent);
            return;
        }
        current = current->next;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]", newStudent->name);

    printf("Enter student grade: ");
    scanf("%f", &newStudent->grade);

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    printf("Student added successfully.\n");
}

// Function to remove a student from the linked list based on their student_id
void removeStudent() {
    if (head == NULL) {
        printf("No students in the list. Cannot remove.\n");
        return;
    }

    int studentID;
    printf("Enter the student ID to remove: ");
    scanf("%d", &studentID);

    struct Student* current = head;
    struct Student* prev = NULL;

    while (current != NULL) {
        if (current->student_id == studentID) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Student with ID %d removed successfully.\n", studentID);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Student with ID %d not found in the list.\n", studentID);
}

// Function to display the details of all students in the linked list
void displayStudents() {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    struct Student* current = head;
    printf("Student List:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", current->student_id, current->name, current->grade);
        current = current->next;
    }
}

// Function to search for a student in the linked list based on their student_id
void searchStudent() {
    if (head == NULL) {
        printf("No students in the list. Cannot search.\n");
        return;
    }

    int studentID;
    printf("Enter the student ID to search: ");
    scanf("%d", &studentID);

    struct Student* current = head;

    while (current != NULL) {
        if (current->student_id == studentID) {
            printf("Student found:\n");
            printf("ID: %d, Name: %s, Grade: %.2f\n", current->student_id, current->name, current->grade);
            return;
        }
        current = current->next;
    }

    printf("Student with ID %d not found in the list.\n", studentID);
}

// Function to count the number of students in the linked list
void countStudents() {
    int count = 0;
    struct Student* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    printf("Total number of students: %d\n", count);
}

// Function to free the memory allocated for the linked list
void cleanup() {
    struct Student* current = head;
    while (current != NULL) {
        struct Student* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice;
    do {
        printf("\n--- Linked List Management System ---\n");
        printf("1. Add a student\n");
        printf("2. Remove a student\n");
        printf("3. Display all students\n");
        printf("4. Search for a student\n");
        printf("5. Count the number of students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                countStudents();
                break;
            case 6:
                cleanup();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
