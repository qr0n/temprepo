#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void makeUser() {
    FILE* file;
    char username[50];
    char password[50];

    printf("What's the username?\n> ");
    scanf("%s", username);
    printf("What's the password?\n> ");
    scanf("%s", password);

    file = file = fopen("CustomerLogin.txt", "w");
    fprintf(file, "%s,%s", username, password);
    printf("User made successfully");
}

//Customer Login Function
bool customer_login() {
    FILE* file;
    char username[50];
    char password[50];
    char line[50];

    // Prompt the customer to enter a username and password
    printf("Enter your customer username: ");
    scanf("%s", username);
    printf("Enter your customer password: ");
    scanf("%s", password);

    // Check if the entered information is part of the customer file
    file = fopen("CustomerLogin.txt", "r");
    while (fgets(line, 50, file) != NULL) {                                         // 
        char* token = strtok(line, ",");                                            //
        char stored_username[50];                                                   // Allocate memory for username
        strcpy(stored_username, token);                                             // Copy username to allocated memory
        
        token = strtok(NULL, ",");
        char stored_password[50]; // Allocate memory for password
        strcpy(stored_password, token); // Copy password to allocated memory

        // Compare the entered username and password with the stored ones
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            printf("Login successful\n");
            fclose(file);
            return true;
        }
    }
    printf("Login unsuccessful\n");
    fclose(file);
    return false;
}

// Admin Login Function
bool admin_login() {
    FILE* file;
    char username[50];
    char password[50];
    char line[50];
    // Prompt the admin to enter a username and password
    
    printf("Enter your admin username: ");
    scanf("%s", username);
    printf("Enter your admin password: ");
    scanf("%s", password);
    
    // Check if the entered information is part of the admin file
    file = fopen("AdminLogin.txt", "r");
    while (fgets(line, 50, file) != NULL) {
        char* token = strtok(line, ",");
        char stored_username[50]; // Allocate memory for username
        strcpy(stored_username, token); // Copy username to allocated memory
        
        token = strtok(NULL, ",");
        char stored_password[50]; // Allocate memory for password
        strcpy(stored_password, token); // Copy password to allocated memory
        
        // Compare the enterred username and password with the stored ones
        printf(" It works i think lol ");
}
}
int main() {
    int i_operation;
    printf("1 : admin login\n2 : customer login\n> ");
    scanf("%d", &i_operation);
    switch (i_operation) {
        case 1:
        admin_login();
        break;
        
        case 2:
        customer_login();
        break;

        case 3:
        makeUser();
        break;
        
        default:
        break;
    }
}
