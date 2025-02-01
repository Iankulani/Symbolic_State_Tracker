#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAR_NAME_LENGTH 50
#define MAX_VARS 10

// Structure to represent a symbolic variable
typedef struct {
    char name[MAX_VAR_NAME_LENGTH];
    char value[MAX_VAR_NAME_LENGTH];  // symbolic value
} SymbolicVar;

// Global array of symbolic variables
SymbolicVar symbolicVars[MAX_VARS];
int varCount = 0;

// Function prototypes
void promptForInput();
void defineSymbolicVariable();
void displaySymbolicState();
void performSymbolicOperation();
void exitTool();

// Function to prompt the user to enter symbolic variable values
void defineSymbolicVariable() {
    if (varCount >= MAX_VARS) {
        printf("Error: Maximum number of variables reached.\n");
        return;
    }

    char varName[MAX_VAR_NAME_LENGTH];
    char varValue[MAX_VAR_NAME_LENGTH];

    printf("Enter the variable name (max length 50): ");
    scanf("%s", varName);
    
    printf("Enter the symbolic value for %s: ", varName);
    scanf("%s", varValue);

    // Add the symbolic variable to the global array
    strcpy(symbolicVars[varCount].name, varName);
    strcpy(symbolicVars[varCount].value, varValue);
    varCount++;

    printf("Symbolic variable %s set to %s.\n", varName, varValue);
}

// Function to display the current symbolic state of all variables
void displaySymbolicState() {
    if (varCount == 0) {
        printf("No symbolic variables defined yet.\n");
        return;
    }

    printf("\nCurrent Symbolic State:\n");
    for (int i = 0; i < varCount; i++) {
        printf("Variable: %s, Symbolic Value: %s\n", symbolicVars[i].name, symbolicVars[i].value);
    }
}

// Function to perform symbolic operations (e.g., addition, comparison)
void performSymbolicOperation() {
    char op[10];
    char var1[MAX_VAR_NAME_LENGTH], var2[MAX_VAR_NAME_LENGTH];
    char resultVar[MAX_VAR_NAME_LENGTH];
    
    printf("Enter the operation (e.g., ADD, SUB):");
    scanf("%s", op);

    printf("Enter the name of the first variable:");
    scanf("%s", var1);
    
    printf("Enter the name of the second variable:");
    scanf("%s", var2);

    // Check if variables exist
    int index1 = -1, index2 = -1;
    for (int i = 0; i < varCount; i++) {
        if (strcmp(symbolicVars[i].name, var1) == 0) {
            index1 = i;
        }
        if (strcmp(symbolicVars[i].name, var2) == 0) {
            index2 = i;
        }
    }

    if (index1 == -1 || index2 == -1) {
        printf("Error: One or both variables do not exist.\n");
        return;
    }

    // Perform the symbolic operation
    if (strcmp(op, "ADD") == 0) {
        sprintf(resultVar, "(%s + %s)", symbolicVars[index1].value, symbolicVars[index2].value);
    } else if (strcmp(op, "SUB") == 0) {
        sprintf(resultVar, "(%s - %s)", symbolicVars[index1].value, symbolicVars[index2].value);
    } else {
        printf("Error: Unsupported operation.\n");
        return;
    }

    printf("Result of operation: %s\n", resultVar);
}

// Function to display the menu and handle user choices
void displayMenu() {
    int userChoice;

    printf("\nSymbolic State Tracker\n");
    printf("1. Define a symbolic variable\n");
    printf("2. Display current symbolic state\n");
    printf("3. Perform symbolic operation\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &userChoice);
    getchar();  // Consume newline character

    switch (userChoice) {
        case 1:
            defineSymbolicVariable();
            break;
        case 2:
            displaySymbolicState();
            break;
        case 3:
            performSymbolicOperation();
            break;
        case 4:
            exitTool();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

// Function to exit the tool
void exitTool() {
    printf("Exiting the Symbolic State Tracker.\n");
    exit(0);
}

// Main program loop
int main() {
    printf("Welcome to the Symbolic State Tracker\n");

    // Main program loop
    while (1) {
        displayMenu();
    }

    return 0;
}
