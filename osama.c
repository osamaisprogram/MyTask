#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

typedef struct {
    char username[20];
    char password[20];
} User;

User users[MAX_USERS];
int userCount = 0;

int registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Registration failed. Maximum user limit reac  hed.\n");
        return 0;
    }

    User newUser;

    printf("Enter a username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Registration failed.\n");
            return 0;
        }
    }

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("Registration successful.\n");

    return 1;
}

int loginUser() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            return 1;
        }
    }

    printf("Login failed. Incorrect username or password.\n");
    return 0;
}

int main() {
    int choice;
    int loggedIn = 0;

    while (1) {
        printf("1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (registerUser()) {
                    // Registration successful
                }
                break;
            case 2:
                if (loginUser()) {
                    loggedIn = 1;
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}