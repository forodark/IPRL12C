#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glencrypt.h"

#define MAX_NAME 64
#define MAX_WITHDRAWAL 4000

struct account {
    char account_number[64];
    char pin[64];
    double balance;
    char name[MAX_NAME];
    int is_locked;
    int deposit_count;
    int withdraw_count;
    double total_deposit;
    double total_withdraw;
};

void login(struct account accounts[]);
void showMenu(struct account accounts[]);
void balanceInquiry(struct account accounts[]);
void deposit(struct account accounts[]);
void withdrawal(struct account accounts[]);
void logout(struct account accounts[]);
void exitProgram();
void newTransaction(struct account accounts[]);
void lockedAccount(struct account accounts[]);
void generateReport(struct account accounts[]);

int n, selection;

int main() {
    printf("Welcome to LPU Bank!\n");

    printLine();
    struct account accounts[] = { //The PIN is encrypted through glencrypt.h passwords are shown as comments next to the struct
        {"1001", "IHGFED", 5000.00, "Glen", 0, 0, 0, 0.0, 0.0}, //000000
        {"1002", "KLMNOP", 5000.00, "Angelo", 1, 0, 0, 0.0, 0.0}, //123456 (LOCKED)
        {"1003", "MPSV", 5000.00, "Yui", 0, 0, 0, 0.0, 0.0}, //2468
        {"1004", "INGXGT", 99999.00, "Happy", 0, 0, 0, 0.0, 0.0}, //030918
        {"1005", "IPKT", 0.00, "Forodark", 0, 0, 0, 0.0, 0.0} //0427
    };
    n = sizeof(accounts) / sizeof(struct account);
    login(accounts);
    return 0;
}

void login(struct account accounts[]) {
    while(1) {
        char account_number[64];
        inputCustom("Enter account number: ", &account_number, "1234567890");
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
                    inputCustom("Enter PIN: ", &pin, "1234567890");
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
    printf("[5] Generate Report\n");
    printf("[6] Admin Panel\n");
    printf("[7] Exit\n\n");
    while (1) {
        input(INT, "Enter transaction number: ", &choice);
        switch (choice) {
            case 1:
                printLine();
                balanceInquiry(accounts);
                break;
            case 2:
                printLine();
                deposit(accounts);
                break;
            case 3:
                printLine();
                withdrawal(accounts);
                break;
            case 4:
                printLine();
                logout(accounts);
                break;
            case 5:
                printLine();
                generateReport(accounts);
                break;
            case 6:
                printLine();
                loginAdmin(accounts);
                break;
            case 7:
                printLine();
                exitProgram();
            default:
                printf("Invalid choice.\n");
                printLine();
                continue; 
        }
        break;
    }
}

void balanceInquiry(struct account accounts[]) {
    printf("Account balance: Php %.2lf\n", accounts[selection].balance);
    printLine();
    newTransaction(accounts);
}

void deposit(struct account accounts[]) {
    double amount;
    input(DOUBLE, "Enter amount to deposit: ", &amount);
    printLine();
    if (amount > 0) {
        accounts[selection].balance += amount;
        printf("Successfully deposited Php %.2lf.\nNew balance: Php %.2lf\n", amount, accounts[selection].balance);
        accounts[selection].deposit_count += 1;
        accounts[selection].total_deposit += amount;
    }
    else {
        printf("Deposit amount should be greater than zero\n");
    }
    printLine();
    newTransaction(accounts);
}

void withdrawal(struct account accounts[]) {
    while (1) {
        double amount;
        input(DOUBLE, "Enter amount to withdraw: ", &amount);
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
            printf("Withdrawal successful.\nNew balance: Php %.2lf\n", accounts[selection].balance);
            accounts[selection].withdraw_count += 1;
            accounts[selection].total_withdraw += amount;
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
    int choice;
    while (1) {
        input(BOOL, "Would you like to do another transaction? [y/n]: ", &choice);
        if (choice == 1) {
            printLine();
            showMenu(accounts);
            return;
        } 
        else if (choice == 0) {
            printLine();
            exitProgram();
            return;
        }
    }
}

void lockedAccount(struct account accounts[]) {
    printf("Your account has been temporarily locked for your security. Please contact an administrator for assistance or try a different account.\n");
    printLine();
    login(accounts);
}

void generateReport(struct account accounts[]) {
    printf("Deposit Count: %d\n", accounts[selection].deposit_count);
    printf("Withdrawal Count: %d\n", accounts[selection].withdraw_count);
    printf("Total Amount Deposited: %.2lf\n", accounts[selection].total_deposit);
    printf("Total Amount Withdrawn: %.2lf\n", accounts[selection].total_withdraw);
    printLine();
    newTransaction(accounts);
}

void loginAdmin(struct account accounts[]) {
    while(1) {
        char pass[64];
        char admin_pass[] = "";
        inputCustom("Enter Admin Password: ", &pass, ALPHANUM);
        if (!strcmp(decrypt(admin_pass), pass)) {
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

void showAdminMenu(struct account accounts[]) {
    int choice;
    printf("[1] List Accounts\n");
    printf("[2] Create Account\n");
    printf("[3] Edit Account\n");
    printf("[4] Return\n");
    while (1) {
        input(INT, "Enter transaction number: ", &choice);
        switch (choice) {
            case 1:
                printLine();
                balanceInquiry(accounts);
                break;
            case 2:
                printLine();
                deposit(accounts);
                break;
            case 3:
                printLine();
                withdrawal(accounts);
                break;
            case 4:
                printLine();
                exitProgram();
            default:
                printf("Invalid choice.\n");
                printLine();
                continue; 
        }
        break;
    }
}

void generateReport(struct account accounts[]) {
    printf("Deposit Count: %d\n", accounts[selection].deposit_count);
    printf("Withdrawal Count: %d\n", accounts[selection].withdraw_count);
    printf("Total Amount Deposited: %.2lf\n", accounts[selection].total_deposit);
    printf("Total Amount Withdrawn: %.2lf\n", accounts[selection].total_withdraw);
    printLine();
    newTransaction(accounts);
}
