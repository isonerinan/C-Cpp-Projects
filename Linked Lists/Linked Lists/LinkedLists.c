// Ýbrahim Soner ÝNAN - 040200075
// C program for linked list implementation of stack
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LIMIT 40
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct StackNode {
    int intData;
    char strData;
    struct StackNode* next;
};


//Function to add a new node to the linked list/stack
struct StackNode* newNode(int intData, char strData)
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

    if (stackNode) {
        stackNode->intData = intData;
        stackNode->strData = strData;
        stackNode->next = NULL;
        return stackNode;
    }
    
}

// Function to check if a stack is empty
int isEmpty(struct StackNode* root)
{
    return !root;
}

// Function to add data to the top of the stack
void push(struct StackNode** root, int intData, char strData)
{
    struct StackNode* stackNode = newNode(intData, strData);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to delete and return the data from the top of the stack (pop)
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;

    int popped = NULL;

    if (temp->intData == NULL) {
        popped = temp->strData;
    }

    if (temp->strData == NULL) {
        popped = temp->intData;
    }
    free(temp);

    return popped;
}


// Unordered stacks to keep all students from newly added to old
struct StackNode* unorderedName;
unorderedName = newNode(NULL, NULL);
struct StackNode* unorderedFaculty;
unorderedFaculty = newNode(NULL, NULL);
struct StackNode* unorderedYear;
unorderedYear = newNode(NULL, NULL);
struct StackNode* unorderedID;
unorderedID = newNode(NULL, NULL);

int input;

int main() {
    
    // Loop because we need to perform tasks as much as we want
    while (1) {
        printf("\n---MAIN MENU---\n"

            "What do you want to do?\n"
            "1. Enter a new record\n"
            "2. Delete a record\n"
            "3. Display the current records by ID\n"
            "4. Display the current records by year\n"
            "5. Display the current records by faculty code\n"
            "6. Quit\n");

        scanf("%d", &input);

        // Enter new record (Name, surname, ID)
        // Derives faculty code, year, ID from the school number
        if (input == 1) {
            printf("\nPlease enter the name of the student: ");
            char name[MAX_LIMIT];
            scanf("%s", &name);

            printf("\nPlease enter the surname of the student: ");
            char surname[MAX_LIMIT];
            scanf("%s", &surname);

            printf("\nPlease enter the student ID: ");
            char schoolNumber[9];
            scanf("%s", &schoolNumber);

            // Save name and surname
            struct StackNode* nameHead;
            nameHead = newNode(NULL, NULL);

            for (int i = 0; name != "\0"; i++) {
                push(nameHead, NULL, name[i]);
            }

            push(nameHead, NULL, " ");

            for (int i = 0; surname != "\0"; i++) {
                push(nameHead, NULL, surname[i]);
            }

            // Push the name & surname to the stack
            push(unorderedName, NULL, nameHead);

            // Derive faculty code
            struct StackNode* facultyHead;
            facultyHead = newNode(NULL, NULL);
            for (int i = 0; i < 3; i++) {
                push(facultyHead, (int)schoolNumber[i], NULL);
            }

            // Push the faculty code to the stack
            push(unorderedFaculty, facultyHead, NULL);

            // Derive year
            struct StackNode* yearHead;
            yearHead = newNode(NULL, NULL);
            for (int i = 3; i < 5; i++) {
                push(yearHead, (int)schoolNumber[i], NULL);
            }

            // Push the year to the stack
            push(unorderedYear, yearHead, NULL);

            // Derive ID
            struct StackNode* idHead;
            idHead = newNode(NULL, NULL);
            for (int i = 5; i < 9; i++) {
                push(idHead, (int)schoolNumber[i], NULL);
            }

            // Push the ID to the stack
            push(unorderedID, idHead, NULL);

            printf("Saved: %s %s - %s\n", &name, &surname, &schoolNumber);
        }

        // Delete a node from the unordered stack by school number
        if (input == 2) {
            printf("\nEnter the school number to delete: ");

            // Display the numbers available to be deleted
            //      Code needed here

            int deleteNum;
            scanf("%d", &deleteNum);
        }

        // Display by ID
        if (input == 3) {
            // Code needed here
        }

        // Display by year
        if (input == 4) {
            // Code needed here
        }

        // Display by faculty
        if (input == 5) {
            // Code needed here
        }

        // Quit
        if (input == 6) {
            break;
        }
    }


}