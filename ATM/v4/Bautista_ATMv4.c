#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glencrypt.h"

#define MAX_NAME 64
#define MAX_WITHDRAWAL 4000
#define MAX_ACCOUNTS 256

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
void showAdminMenu(struct account accounts[]);
void listAccounts(struct account accounts[]);
void createAccount(struct account accounts[]);
void editAccount(struct account accounts[]);
void newAdminTransaction(struct account accounts[]);


int n, selection;

int main() {
    printf("Welcome to LPU Bank!\n");

    printLine(0);
    struct account accounts[] = { //The PIN is encrypted through glencrypt.h passwords are shown as comments next to the struct
        {"1001", "}Pj? T", 5000.00, "Glen", 0, 0, 0, 0.0, 0.0}, //000000
        {"1002", "~Rm]4Z", 5000.00, "Angelo", 1, 0, 0, 0.0, 0.0}, //123456 (LOCKED)
        {"1003", " Tp{", 5000.00, "Yui", 0, 0, 0, 0.0, 0.0}, //2468
        {"1004", "}Sj|0\"", 99999.00, "Happy", 0, 0, 0, 0.0, 0.0}, //030918
        {"1005", "}Tl`", 0.00, "Forodark", 0, 0, 0, 0.0, 0.0} //0427
    };
    n = sizeof(accounts) / sizeof(struct account);
    login(accounts);
    return 0;
}

void login(struct account accounts[]) {
    while(1) {
        char account_number[64];
        inputCustom("Enter account number: ", &account_number, "1234567890");
        
        if (!strcmp("1000", account_number)) {
		    printLine(0);
        	while(1) {
		        char pass[64];
		        char admin_pass[] = "m+wg0VKv"; //pldt1234
		        inputCustom("Enter Admin Password: ", &pass, ALPHANUM);
		        if (!strcmp(decrypt(admin_pass), pass)) {
		            printLine(0);
		            printf("Welcome Admin!\n\n");
		            showAdminMenu(accounts);
		            return;
		        }
		        else {
		            printf("Incorrect Password\n");
		        }
		        printLine(0);
			}
		}
        
        for (int i = 0; i < n; i++) {
            if (!strcmp(accounts[i].account_number, account_number)) { 
                int attempts = 4;
                printLine(0);
                if (accounts[i].is_locked == 1) {
                    lockedAccount(accounts);
                    return;
                }
                while(attempts > 0) {
                    char pin[64];
                    inputCustom("Enter PIN: ", &pin, "1234567890");
                    if (!strcmp(decrypt(accounts[i].pin), pin)) {
                        selection = i;
                        printLine(0);
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
                    printLine(0);
                }
            }
        }
        printf("Invalid account number.\n");
        printLine(0);
    }
}

void showMenu(struct account accounts[]) {
    int choice;
    printf("[1] Balance Inquiry\n");
    printf("[2] Deposit\n");
    printf("[3] Withdrawal\n");
    printf("[4] Logout/Change Account\n");
    printf("[5] Generate Report\n");
    printf("[6] Exit\n\n");
    while (1) {
        input(INT, "Enter transaction number: ", &choice);
        switch (choice) {
            case 1:
                printLine(0);
                balanceInquiry(accounts);
                break;
            case 2:
                printLine(0);
                deposit(accounts);
                break;
            case 3:
                printLine(0);
                withdrawal(accounts);
                break;
            case 4:
                printLine(0);
                logout(accounts);
                break;
            case 5:
                printLine(0);
                generateReport(accounts);
                break;
            case 6:
                printLine(0);
                exitProgram();
            default:
                printf("Invalid choice.\n");
                printLine(0);
                continue; 
        }
        break;
    }
}

void balanceInquiry(struct account accounts[]) {
    printf("Account balance: Php %.2lf\n", accounts[selection].balance);
    printLine(0);
    newTransaction(accounts);
}

void deposit(struct account accounts[]) {
    double amount;
    input(DOUBLE, "Enter amount to deposit: ", &amount);
    printLine(0);
    if (amount > 0) {
        accounts[selection].balance += amount;
        printf("Successfully deposited Php %.2lf.\nNew balance: Php %.2lf\n", amount, accounts[selection].balance);
        accounts[selection].deposit_count += 1;
        accounts[selection].total_deposit += amount;
    }
    else {
        printf("Deposit amount should be greater than zero\n");
    }
    printLine(0);
    newTransaction(accounts);
}

void withdrawal(struct account accounts[]) {
    while (1) {
        double amount;
        input(DOUBLE, "Enter amount to withdraw: ", &amount);
        printLine(0);
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
            printLine(0);
            newTransaction(accounts);
            
        }
        printLine(0);
    }

}

void logout(struct account accounts[]) {
    selection = -1;
    printf("Logging out...\n");
    printLine(0);
    login(accounts);
}

void exitProgram() {
    printf("Thank you for transacting with LPU Bank. (｡•̀ᴗ-)✧\n");
    printLine(0);
    exit(0);
}

void newTransaction(struct account accounts[]) {
    int choice;
    while (1) {
        input(BOOL, "Would you like to do another transaction? [y/n]: ", &choice);
        if (choice == 1) {
            printLine(0);
            showMenu(accounts);
            return;
        } 
        else if (choice == 0) {
            printLine(0);
            exitProgram();
            return;
        }
    }
}



void lockedAccount(struct account accounts[]) {
    printf("Your account has been temporarily locked for your security. Please contact an administrator for assistance or try a different account.\n");
    printLine(0);
    login(accounts);
}

void generateReport(struct account accounts[]) {
    printf("Deposit Count: %d\n", accounts[selection].deposit_count);
    printf("Withdrawal Count: %d\n", accounts[selection].withdraw_count);
    printf("Total Amount Deposited: %.2lf\n", accounts[selection].total_deposit);
    printf("Total Amount Withdrawn: %.2lf\n", accounts[selection].total_withdraw);
    printLine(0);
    newTransaction(accounts);
}

void showAdminMenu(struct account accounts[]) {
    int choice;
    printf("[1] List Accounts\n");
    printf("[2] Create Account\n");
    printf("[3] Edit Account\n");
    printf("[4] Return\n\n");
    while (1) {
        input(INT, "Enter transaction number: ", &choice);
        switch (choice) {
            case 1:
                listAccounts(accounts);
                break;
            case 2:
                printLine(0);
                createAccount(accounts);
                break;
            case 3:
                printLine(0);
            editAccount(accounts);
                break;
            case 4:
                printLine(0);
                logout(accounts);
            default:
                printf("Invalid choice.\n");
                printLine(0);
                continue; 
        }
        break;
    }
}

void listAccounts(struct account accounts[]) {
	printLine(2);
    printf(" ACCTNO. |   PIN   |     BALANCE     |            NAME            \n");
    for(int i=0; i < n; i++) {
    	printf(" %7s | %-6s  | %-15.2lf | %-27s \n", accounts[i].account_number, decrypt(accounts[i].pin), accounts[i].balance, accounts[i].name);
	}
    printLine(2);
    newAdminTransaction(accounts);
}

void createAccount(struct account accounts[]) {
    if (n >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached. Cannot create a new account.\n");
        return;
    }

    printf("Create Account\n");
    printLine(0);

    sprintf(accounts[n].account_number, "%d", 1000 + n + 1);

    inputCustom("Enter Name: ", accounts[n].name, ALPHANUM);
    printLine(0);
    while (1) {
    	char pin[64];
        inputCustom("Enter PIN: ", &pin, "0123456789");
        printLine(0);
        char confirm_pin[64];
        inputCustom("Confirm PIN: ", confirm_pin, "0123456789");
        if (strcmp(pin, confirm_pin) == 0) {
        	strcpy(accounts[n].pin, encrypt(pin));
        	printLine(0);
            break;
        } else {
            printf("PINs do not match. Please try again.\n");
            printLine(0);
        }
    }
    accounts[n].balance = 0.0;

    accounts[n].is_locked = 0;
    accounts[n].deposit_count = 0;
    accounts[n].withdraw_count = 0;
    accounts[n].total_deposit = 0.0;
    accounts[n].total_withdraw = 0.0;

    printf("New account (%s) created successfully!\n", accounts[n].account_number);
    
    n += 1;
    newAdminTransaction(accounts);
}

void editAccount(struct account accounts[]) {
	while(1) {
		char account_number[64];
	    inputCustom("Enter account number: ", &account_number, "1234567890");
	    printLine(0);
	    
		for (int i = 0; i < n; i++) {
	        if (!strcmp(accounts[i].account_number, account_number)) { 
	    		selection = i;
	    		int edit_choice;
    			printf("[1] Name\n");
		        printf("[2] PIN\n");
		        printf("[3] Lock/Unlock\n\n");
			    while (1) {

			        input(INT, "Enter the field to edit: ", &edit_choice);
			        
			        			
				    switch (edit_choice) {
				        case 1: {
				            char new_name[MAX_NAME];
							printLine(0);
				            inputCustom("Enter Name: ", new_name, ALPHANUM);
				            strcpy(accounts[selection].name, new_name);
				            printf("Name updated successfully.\n");
				            break;
				        }
				        case 2: {
				            while (1) {
				            	printLine(0);
				                char new_pin[64];
				                inputCustom("Enter the new PIN: ", new_pin, "0123456789");
				                printLine(0);
				                if (strlen(new_pin) != 6 && strlen(new_pin) != 4) {
			                        printf("Invalid input. PIN length must be 4 or 6.\n");
			                        printLine(0);
			                    }
			                    else {
				                    char confirmPin[64];
					                inputCustom("Confirm the new PIN: ", confirmPin, "0123456789");
					                if (!strcmp(new_pin, confirmPin)) {
					                    strcpy(accounts[selection].pin, encrypt(new_pin));
					                    printf("PIN updated successfully.\n");
					                    printLine(0);
					                    break;
					                } else {
					                    printf("PINs do not match. Please try again.\n");
					                    printLine(0);
					                }
								}

				            }
				            break;
				        }
				        case 3: {
				        	printLine(0);
				            accounts[selection].is_locked = !accounts[selection].is_locked;
				            if (accounts[selection].is_locked) {
				                printf("Account locked successfully.\n");
				            } else {
				                printf("Account unlocked successfully.\n");
				            }
				            break;
				        }
				        default: {
				            printf("Invalid choice. Please try again.\n");
				            printLine(0);
							continue;
						}
				    }
				    printLine(0);
				    newAdminTransaction(accounts);
			    }

			}
	    }
		printf("Invalid account number.\n");
		printLine(0);
	}



    
}


void newAdminTransaction(struct account accounts[]) {
    int choice;
    while (1) {
        input(BOOL, "Would you like to do another transaction? [y/n]: ", &choice);
        if (choice == 1) {
            printLine(0);
            showAdminMenu(accounts);
            return;
        } 
        else if (choice == 0) {
            printLine(0);
            exitProgram();
            return;
        }
    }
}
