#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Structure to hold user information
struct User {
    char username[100];
    char password[100];
    union {
        bool flag;
        int num;
    } login;
};

// Function to register a new user
void registerUser(struct User users[], int *count) {
    printf("Enter username: ");
    scanf("%s", users[*count].username);
    printf("Enter password: ");
    scanf("%s", users[*count].password);
    printf("Enter 1 or 0 or true or false to set login flag: ");
    char input[6];
    scanf("%s", input);
    if (strcmp(input, "true") == 0 || strcmp(input, "1") == 0) {
        users[*count].login.flag = true;
        users[*count].login.num = 1;
    } else if (strcmp(input, "false") == 0 || strcmp(input, "0") == 0) {
        users[*count].login.flag = false;
        users[*count].login.num = 0;
    } else {
        printf("Invalid input. Login flag set to false.\n");
        users[*count].login.flag = false;
        users[*count].login.num = 0;
    }
    *count += 1;
}

// Function to login a user
int loginUser(struct User users[], int count) {
    char username[100];
    char password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].login.flag) {
                printf("Login successful. Welcome, %s!\n", users[i].username);
                return 1;
            } else {
                printf("Login failed. You are not authorized to login.\n");
                return 0;
            }
        }
    }

    printf("Login failed. Invalid User name or password.\n");
    return 0;
}

int main() {
    struct User users[100]; // Maximum of 100 users
    int count = 0; // Number of registered users

    int choice;
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerUser(users, &count);
                break;
            case 2:
                if (loginUser(users, count))
                    return 0; // Successful login, exit program
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
