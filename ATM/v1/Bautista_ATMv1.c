#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glencrypt.h"

#define MAX_NAME 64
#define MAX_WITHDRAWAL 4000

struct account {
    char account_number[64];
    char pin[64];
    float balance;
    char name[MAX_NAME];
    int is_locked;
};

void login(struct account accounts[]);
void showMenu(struct account accounts[]);
void balanceInquiry(struct account accounts[]);
void deposit(struct account accounts[]);
void withdrawal(struct account accounts[]);
void logout(struct account accounts[]);
void exitProgram();
void newTransaction(struct account accounts[]);
void printLine();
void lockedAccount(struct account accounts[]);

int n, selection;

int main() {
    printf("Welcome to LPU Bank!\n");

    printLine();
    struct account accounts[] = {
        {"1001", "IHGFED", 5000.00, "Glen", 0}, //000000
        {"1002", "KLMNOP", 5000.00, "Angelo", 1}, //123456
        {"1003", "MPSV", 5000.00, "Yui", 0}, //2468
        {"1004", "INGXGT", 99999.00, "Happy", 0} //030918
    };
    n = sizeof(accounts) / sizeof(struct account);
    login(accounts);
    return 0;
}

void login(struct account accounts[]) {
    while(1) {
        char account_number[64];
        printf("Enter account number: ");
        scanf("%s", account_number);
        for (int i = 0; i < n; i++) {
            if (!strcmp(accounts[i].account_number, account_number)) { 
                int attempts = 4;
                printLine();
                if (accounts[i].is_locked == 1) {
                    lockedAccount(accounts);
                    return;
                }
                while(attempts > 0) {
                    char pin[64];
                    printf("Enter PIN: ");
                    scanf("%s", pin);
                    if (!strcmp(decrypt(accounts[i].pin), pin)) {
                        selection = i;
                        printLine();
                        printf("Welcome %s!\n\n", accounts[selection].name);
                        showMenu(accounts);
                        return;
                    }
                    else if (strlen(pin) != 6 && strlen(pin) != 4) {
                        printf("Invalid input. PIN length must be 4 or 6.\n");    
                    }
                    else {
                        attempts -= 1;
                        if (attempts > 1) {
                            printf("Incorrect PIN. %d attempts remaining.\n", attempts);
                        }
                        else if (attempts == 1) {
                            printf("Incorrect PIN. %d attempt remaining.\n", attempts);
                        }
                        else {
                            accounts[i].is_locked = 1;
                            lockedAccount(accounts);
                            return;
                        }
                    }
                    printLine();
                }
            }
        }
        printf("Invalid account number.\n");
        printLine();
    }
}

void showMenu(struct account accounts[]) {
    int choice;
    printf("[1] Balance Inquiry\n");
    printf("[2] Deposit\n");
    printf("[3] Withdrawal\n");
    printf("[4] Logout/Change Account\n");
    printf("[5] Exit\n\n");
    printf("Enter transaction number: ");
    scanf("%d", &choice);
    printLine();
    switch (choice) {
        case 1:
            balanceInquiry(accounts);
            break;
        case 2:
            deposit(accounts);
            break;
        case 3:
            withdrawal(accounts);
            break;
        case 4:
            logout(accounts);
            break;
        case 5:
            exitProgram();
        default:
            printf("Invalid choice.\n");
            printLine();
            showMenu(accounts);
    }
}

void balanceInquiry(struct account accounts[]) {
    printf("Account balance: Php %.2f\n", accounts[selection].balance);
    printLine();
    newTransaction(accounts);
}

void deposit(struct account accounts[]) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    printLine();
    if (amount > 0) {
        accounts[selection].balance += amount;
        printf("Deposit successful.\nNew balance: Php %.2f\n", accounts[selection].balance);
    }
    else {
        printf("Deposit amount should be greater than zero\n");
    }
    printLine();
    newTransaction(accounts);
}

void withdrawal(struct account accounts[]) {
    while (1) {
        float amount;
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        printLine();
        if (amount > accounts[selection].balance) {
            printf("Withdrawal amount exceeds the available balance.\n");
        } 
        else if (amount <= 0) {
            printf("Withdrawal amount should be greater than zero.\n");
        }
        else if (amount > MAX_WITHDRAWAL) {
            printf("Maximum withdrawal amount is Php 4000.00.\n");
        }
        else {
            accounts[selection].balance -= amount;
            printf("Withdrawal successful.\nNew balance: Php %.2f\n", accounts[selection].balance);
            printLine();
            newTransaction(accounts);
            
        }
        printLine();
    }

}

void logout(struct account accounts[]) {
    selection = -1;
    printf("Logging out...\n");
    printLine();
    login(accounts);
}

void exitProgram() {
    printf("Thank you for transacting with LPU Bank. (｡•̀ᴗ-)✧\n");
    printLine();
    exit(0);
}

void newTransaction(struct account accounts[]) {
    char buffer[64];
    char choice;
    printf("Would you like to do another transaction? [y/n]: ");
    while (1) {
        fgets(buffer, 64, stdin);
        if (buffer[0] == '\n') {
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        if (sscanf(buffer, " %c", &choice) != 1) {
            printLine();
            printf("Invalid input. Please enter [y/n]: ");
        }
        else if (choice == 'y' || choice == 'Y') {
            printLine();
            showMenu(accounts);
            return;
        } 
        else if (choice == 'n' || choice == 'N') {
            exitProgram();
            return;
        }
        else {
            printLine();
            printf("Invalid input. Please enter [y/n]: ");
        }
    }
}

void printLine() {
    printf("---------------------------------\n");
}

void lockedAccount(struct account accounts[]) {
    printf("Your account has been temporarily locked for your security. Please contact an administrator for assistance or try a different account.\n");
    printLine();
    login(accounts);
}