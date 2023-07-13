// ATM V5 FINAL VERSION (PROBABLY)
//Admin credentials:
//Account Number: 1000
//Password: admin

//Key features:
//File structure
//Encrypted passwords
//Admin panel
//Create/edit/delete accounts
//Accounts get locked

//v6 changes
//Fixed deposit function
//Added transfer money feature
//added transaction struct, and display for 5 most recent transactions

//v7 changes
//added view transaction log to admin panel with pages
//changed recent transactions to transaction log with page support
//improved transaction type data type and passing
//added way to exit from entering acct number and pin
//clear command line at certain points to improve readability
//added page support for acc list
//improved variables names for better code readability
//removed newAdminTransaction(), replaced with waitEnter() where its needed
//decluttered and denested as much as i can
//made struct accounts a global variable and removed the parameter passing for accounts
//added view details feature on editAccount()
//added transaction type for deleted account and confirm before account deleting
//separate transaction type for sent and received money, two records will be created one for each account
//reentered all default account and transaction data
//improved text prompts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glencrypt.h"

#define MAX_NAME 64
#define MAX_WITHDRAWAL 4000
#define MAX_ACCOUNTS 256
#define MAX_TRANSACTIONS 1024
#define PAGE_LENGTH 10

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

struct transaction {
    char transaction_id[64];
    char account_number[64];
    char type[20];
    double amount;
    char date[20];
    char time[20];
};

void login();
void loginAdmin();

void showMenu();
void showAdminMenu();

void balanceInquiry();
void deposit();
void withdrawal();
void transfer();
void generateReport();
void logout();
void exitProgram();

void listAccounts();
void createAccount();
void editAccount();
void viewDetails();
void changeName();
void changePIN();
void lockUnlock();
void deleteAccount();

void newTransaction();
void lockedAccount();
void saveAccounts();
void loadAccounts();
void recordTransaction(int type, double amount);
void listTransactions();
void listAllTransactions();

struct transaction transactions[MAX_TRANSACTIONS];
struct account accounts[MAX_ACCOUNTS];
int accounts_size, transactions_size;
int selection = -1; int transfer_to = -1;

int main() {
	printLine(1);
    printf("%27s", "Welcome to LPU Bank!\n");
    printLine(1);

    accounts_size = 0; transactions_size = 0;
    loadAccounts();

    login();

    return 0;
}

void login() {
    int attempts = 4;
    int i;
    while(1) {
        char account_number[64];
        int valid = 0;
        inputCustom("Enter account number (0 to exit):\n\t", &account_number, "1234567890");
        
        if (!strcmp("0", account_number)) {
        	exitProgram();
		}
        if (!strcmp("1000", account_number)) {
			loginAdmin();
		}

        for (i = 0; i < accounts_size; i++) {
            if (!strcmp(accounts[i].account_number, account_number)) { 
				valid = 1;
				break;
        	}
    	}
    	if (valid == 0) {
    		    printf("Invalid account number.\n");
		        printLine(0);
                continue;
		}
        if (accounts[i].is_locked == 1) {
            lockedAccount();
        }
        printLine(0);
        break;
	}

    while(attempts > 0) {
        char pin[64];
        inputCustom("Enter PIN (0 to return):\n\t", &pin, "1234567890");
        
        if (!strcmp("0", pin)) {
        	printLine(0);
        	login();
		}
		if (strlen(pin) != 6 && strlen(pin) != 4) {
            printf("Invalid input. PIN length must be 4 or 6.\n");
        	printLine(0);
			continue; 
        }
		if (!strcmp(decrypt(accounts[i].pin), pin)) {
		    selection = i;
		    showMenu();
        }    
        attempts -= 1;
        if (attempts > 1) {
            printf("Incorrect PIN. %d attempts remaining.\n", attempts);
            printLine(0);
        }
        else if (attempts == 1) {
            printf("Incorrect PIN. %d attempt remaining.\n", attempts);
            printLine(0);
        }
        else {
            accounts[i].is_locked = 1;
            lockedAccount();
        }
    }
}

void loginAdmin() {
    printLine(0);
	while(1) {
        char pass[64];
        char admin_pass[] = "7#F5m"; //admin
        inputCustom("Enter Password (0 to return):\n\t", &pass, ALPHANUM);
        
        if (!strcmp("0", pass)) {
        	printLine(0);
        	login();
		}
        
        if (!strcmp(decrypt(admin_pass), pass)) {
            showAdminMenu();
            return;
        }
        else {
            printf("Incorrect Password.\n");
        }
        printLine(0);
	}
}

void showMenu() {
    int choice;
    system("CLS");
    printLine(0);
    printf("Welcome %s!\n\n", accounts[selection].name);
    printf("[1] Balance Inquiry\n");
    printf("[2] Deposit\n");
    printf("[3] Withdrawal\n");
    printf("[4] Transfer Money\n");
    printf("[5] Transaction History\n");
    printf("[6] Generate Report\n");
    printf("[7] Logout/Change Account\n");
    printf("[0] Exit\n\n");
    while (1) {
        input(Int, "Enter transaction number: ", &choice);
        switch (choice) {
            case 1:
                balanceInquiry();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdrawal();
                break;
            case 4:
            	transfer();
                break;
            case 5:
            	listTransactions();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                logout();
                break;
            case 0:
                exitProgram();
            default:
                printf("Invalid choice.\n");
                printLine(0);
                continue; 
        }
        break;
    }
}

void showAdminMenu() {
	saveAccounts();
    int choice;
    system("CLS");
    printLine(0);
    printf("Welcome Admin!\n\n");
    printf("[1] List Accounts\n");
    printf("[2] Create Account\n");
    printf("[3] Edit Account\n");
    printf("[4] List All Transactions\n");
    printf("[0] Logout\n\n");
    while (1) {
        input(Int, "Enter transaction number: ", &choice);
        switch (choice) {
            case 1:
                listAccounts();
                break;
            case 2:
                createAccount();
                break;
            case 3:
            	editAccount();
                break;
            case 4:
                listAllTransactions();
                break;
            case 0:
                logout();
                break;
            default:
                printf("Invalid choice.\n");
                printLine(0);
                continue; 
        }
        break;
    }
}

void balanceInquiry() {
	system("CLS");
	printLine(0);
    printf("Account balance: Php %.2lf\n", accounts[selection].balance);
    printLine(0);
    newTransaction();
}

void deposit() {
	system("CLS");
	printLine(0);
	while(1) {
	    double amount;
	    input(Double, "Enter amount to deposit: ", &amount);
	    printLine(0);
	    if (amount <= 0) {
	        printf("Deposit amount should be greater than zero.\n");
	        printLine(0);
	        continue;
	    }
        accounts[selection].balance += amount;
        printf("Successfully deposited Php %.2lf.\nNew balance: Php %.2lf\n", amount, accounts[selection].balance);
        accounts[selection].deposit_count += 1;
        accounts[selection].total_deposit += amount;
        recordTransaction(2, amount);
        printLine(0);
    	newTransaction();
	}
}

void withdrawal() {
	system("CLS");
	printLine(0);
    while (1) {
        double amount;
        input(Double, "Enter amount to withdraw: ", &amount);
        printLine(0);
        if (amount > accounts[selection].balance) {
            printf("Withdrawal amount exceeds the available balance.\n");
            printLine(0);
            continue;
        } 
        if (amount <= 0) {
            printf("Withdrawal amount should be greater than zero.\n");
            printLine(0);
            continue;
        }
        if (amount > MAX_WITHDRAWAL) {
            printf("Maximum withdrawal amount is Php 4000.00.\n");
            printLine(0);
            continue;
        }
        accounts[selection].balance -= amount;
        printf("Withdrawal successful.\nNew balance: Php %.2lf\n", accounts[selection].balance);
        accounts[selection].withdraw_count += 1;
        accounts[selection].total_withdraw += amount;
        recordTransaction(3, amount);
        printLine(0);
        newTransaction();
    }
}

void transfer() {
	system("CLS");
	printLine(0);
    while(1) {
		char account_number[64];
	    inputCustom("Enter receiving account number: ", &account_number, "1234567890");
	    if (!strcmp(accounts[selection].account_number, account_number)) {
	    	printf("You cannot transfer funds to yourself.\n");
	    	printLine(0);
	    	continue;
		}
		for (int i = 0; i < accounts_size; i++) { 		
            if (!strcmp(accounts[i].account_number, account_number)) { 
                transfer_to = i;
                printLine(0);
        	}
		}	
		if (transfer_to == -1) {
			printf("Invalid account number.\n");
			printLine(0);
			continue;
		}
		break;
	}
	
	while(1) {
	    double amount;
	    input(Double, "Enter amount to transfer: ", &amount);
	    
	    if (amount <= 0) {
	        printf("Transfer amount should be greater than zero.\n");
	        printLine(0);
	        continue;
	    }
	    if (amount > accounts[selection].balance) {
	    	printf("Insufficient funds.\n");
	    	printLine(0);
	    	continue;
		}
    	printLine(0);
        accounts[selection].balance -= amount;
        accounts[transfer_to].balance += amount;
        printf("Successfully transferred Php %.2lf to %s (%s).\nNew balance: Php %.2lf\n",
		amount, accounts[transfer_to].name, accounts[transfer_to].account_number, accounts[selection].balance);
    	recordTransaction(4, amount);
        transfer_to = -1;
		printLine(0);
    	newTransaction();
	}
}

void generateReport() {
	system("CLS");
	printLine(0);
    printf("Deposit Count: %d\n", accounts[selection].deposit_count);
    printf("Withdrawal Count: %d\n", accounts[selection].withdraw_count);
    printf("Total Amount Deposited: %.2lf\n", accounts[selection].total_deposit);
    printf("Total Amount Withdrawn: %.2lf\n", accounts[selection].total_withdraw);
    printLine(0);
    newTransaction();
}

void logout() {
	system("CLS");
	printLine(0);
    selection = -1;
    printf("Logging out...\n");
    printLine(0);
    login();
}

void exitProgram() {
	saveAccounts();
	printLine(1);
    printf("Thank you for transacting with LPU Bank. <3\n");
    printLine(1);
    exit(0);
}

void listAccounts() {
	
	int i; int j = 0;
	int page = 0; int max_page = (accounts_size-1)/PAGE_LENGTH;
	int item_count = 0;
	
	while(1) {
		system("CLS");
		printLine(2);
	    printf("Accounts List:\n");
		printLine(2);
	    printf(" ACCTNO. |   PIN   |     BALANCE     |        NAME        | STATUS\n");
	    for(i=item_count; j<PAGE_LENGTH && i<accounts_size ; i++,j++) {
	    	char status[8];
	    	if(accounts[i].is_locked == 0) {
	    		strcpy(status, "Active");
			}
			else if(accounts[i].is_locked == 1) {
	    		strcpy(status, "Locked");
			}
	    	printf(" %7s | %-6s  | %-15.2lf | %-18s | %6s\n", accounts[i].account_number, decrypt(accounts[i].pin), accounts[i].balance, accounts[i].name, status);
		}
		j = 0;
	    printLine(2);
		printf(" Page %d/%d    ", page+1, max_page+1);
		if (page > 0) {
			printf("[8] Previous Page    ");
		}
		if (page != max_page) {
			printf("[9] Next Page    ");
		}
		printf("[0] Return\n");
		printLine(2);
		
		int choice;
		while (1) {
	        input(Int, "Enter choice: ", &choice);
	        switch (choice) {
	            case 8:
	            	if (page > 0) {	
						page--;				
						item_count = page*PAGE_LENGTH;
						break;
					}
					else {
		                printf("Invalid choice.\n");
		                printLine(0);
		                continue;
					}
		            
	            case 9:
	            	if (page != max_page) {	
	            		page++;
	            		item_count = page*PAGE_LENGTH;
						break;
					}
					else {
		                printf("Invalid choice.\n");
		                printLine(0);
		                continue;
					}
	            case 0:
					printLine(2);
				    showAdminMenu();
	                break;
	            default:
	                printf("Invalid choice.\n");
	                printLine(0);
	                continue; 
	        }
	        break;
	    }
	}
}

void createAccount() {
	system("CLS");
	printLine(0);
    if (accounts_size >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached. Cannot create a new account.\n");
        waitEnter();
        showAdminMenu();
    }

    printf("%24s", "Create Account\n");
    printLine(0);

    sprintf(accounts[accounts_size].account_number, "%d", 1000 + accounts_size + 1);

    inputCustom("Enter Name: ", accounts[accounts_size].name, ALPHANUM);
    printLine(0);
    while (1) {
    	char pin[64];
        inputCustom("Enter PIN: ", &pin, "0123456789");
        if (strlen(pin) != 6 && strlen(pin) != 4) {
            printf("Invalid input. PIN length must be 4 or 6.\n");
            printLine(0);
            continue;
        }
        char confirm_pin[64];
        printLine(0);
        inputCustom("Confirm PIN: ", confirm_pin, "0123456789");
        if (strcmp(pin, confirm_pin) == 0) {
        	strcpy(accounts[accounts_size].pin, encrypt(pin));
        	printLine(0);
            break;
        } else {
            printf("PINs do not match. Please try again.\n");
            printLine(0);
        }
    }
    accounts[accounts_size].balance = 0.0;

    accounts[accounts_size].is_locked = 0;
    accounts[accounts_size].deposit_count = 0;
    accounts[accounts_size].withdraw_count = 0;
    accounts[accounts_size].total_deposit = 0.0;
    accounts[accounts_size].total_withdraw = 0.0;

	selection = accounts_size;
	recordTransaction(0, 0.0);
	selection = -1;
    printf("New account (%s) created successfully!\n", accounts[accounts_size].account_number);
    printLine(0);
    accounts_size += 1;
    waitEnter();
    showAdminMenu();
}

void editAccount() {
	system("CLS");
	printLine(0);
    if (accounts_size == 0) {
        printf("No accounts found.\n");
        printLine(0);
        waitEnter();
        showAdminMenu();
    }
	char account_number[64];
	while(1) {
	    inputCustom("Enter account number: ", &account_number, "1234567890");

		for (int i = 0; i < accounts_size; i++) {
	        if (!strcmp(accounts[i].account_number, account_number)) { 
	    		selection = i;
	    	}
		}
		if (selection == -1) {
			printf("Invalid account number.\n");
			printLine(0);
			continue;
		}	
		break;
	}
	
	while(1) {
		int choice;
		system("CLS");
		printLine(0);
		printf("Account Selected: %s\n\n", account_number);
		printf("[1] View Details\n");
		printf("[2] Change Name\n");
        printf("[3] Change PIN\n");
        printf("[4] Lock/Unlock\n");
    	printf("[5] Delete Account\n");
    	printf("[6] Change Account Selection\n");
    	printf("[0] Return\n\n");
	    while (1) {
	        input(Int, "Enter choice: ", &choice);		
		    switch (choice) {
		    	case 1:
		    		viewDetails();
		    		break;
		        case 2: 
		        	changeName();
		        	break;
		        case 3: 
					changePIN();
					break;
		        case 4: 
					lockUnlock();
		            break;
                case 5:
					deleteAccount();
                    break;
                case 6:
					selection = -1;
					editAccount();
                    break;
                case 0:
                	printLine(0);
                	selection = -1;
                	showAdminMenu();
                	break;
		        default:
		            printf("Invalid choice. Please try again.\n");
		            printLine(0);
					continue;
		    }
		    printLine(0);
		    waitEnter();
		    break;
	    }	
	}
}

void viewDetails() {
	char status[8];
	if(accounts[selection].is_locked == 0) {
		strcpy(status, "Active");
	}
	else if(accounts[selection].is_locked == 1) {
		strcpy(status, "Locked");
	}
	
	system("CLS");
	printLine(0);
	printf("Account: %s\n", accounts[selection].account_number);
	printLine(0);
	printf("PIN: %s\n", decrypt(accounts[selection].pin));
	printf("Balance: %.2lf\n", accounts[selection].balance);
	printf("Name: %s\n", accounts[selection].name);
	printf("Status: %s\n", status);
}

void changeName() {
    char new_name[MAX_NAME];
	printLine(0);
    inputCustom("Enter Name: ", new_name, ALPHANUM);
    strcpy(accounts[selection].name, new_name);
    printf("Name updated successfully.\n");
}

void changePIN() {
    while (1) {
    	printLine(0);
        char new_pin[64];
        inputCustom("Enter new PIN: ", new_pin, "0123456789");
        printLine(0);
        if (strlen(new_pin) != 6 && strlen(new_pin) != 4) {
            printf("Invalid input. PIN length must be 4 or 6.\n");
        }
        else {
            char confirmPin[64];
            inputCustom("Confirm PIN: ", confirmPin, "0123456789");
            if (!strcmp(new_pin, confirmPin)) {
                strcpy(accounts[selection].pin, encrypt(new_pin));
                printf("PIN updated successfully.\n");
                break;
            }
			else {
                printf("PINs do not match. Please try again.\n");
                printLine(0);
            }
		}

    }
}

void lockUnlock() {
	printLine(0);
    accounts[selection].is_locked = !accounts[selection].is_locked;
    if (accounts[selection].is_locked) {
        printf("Account locked successfully.\n");
    }
	else {
        printf("Account unlocked successfully.\n");
    }
}

void deleteAccount() {
    int choice;
    printLine(0);
    input(Bool, "Confirm account deletion? [y/n]: ", &choice);
	if (choice == 0) {
		printLine(0);
		printf("Account deletion cancelled.\n");
        return;
    }
    for (int j = selection; j < accounts_size - 1; j++) {
        accounts[j] = accounts[j + 1];
    }
    accounts_size += -1;
    recordTransaction(1, 0.0);
    printLine(0);
    printf("Account deleted successfully.\n");
    selection = -1;
    printLine(0);
    waitEnter();
    showAdminMenu();
}

void newTransaction() {
	saveAccounts();
    int choice;
    input(Bool, "Would you like to do another transaction? [y/n]: ", &choice);
    if (choice == 1) {
        printLine(0);
        showMenu();
        return;
    } 
    else if (choice == 0) {
        exitProgram();
        return;
    }
}

void lockedAccount() {
    printf("Your account has been temporarily locked for your security. Please contact an administrator for assistance or try a different account.\n");
    printLine(0);
    login();
}

void saveAccounts() {
    FILE* file = fopen("accounts.dat", "wb");
    if (file == NULL) {
        printf("Error: Unable to save accounts.\n");
        printLine(0);
		return;
    }
    fwrite(accounts, sizeof(struct account), accounts_size, file);
    fclose(file);
}

void loadAccounts() {
    FILE* file = fopen("accounts.dat", "rb");
    if (file == NULL) {
        printf("Error: Unable to load accounts.\n");
        printLine(0);
        return;
    }
    accounts_size = fread(accounts, sizeof(struct account), MAX_ACCOUNTS, file);
    fclose(file); 
}

void recordTransaction(int type, double amount) {
    struct transaction new_transaction;
	
	FILE *file = fopen("transactions.dat", "ab");
	if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
	
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    long num_transactions = file_size / sizeof(struct transaction);
    
    sprintf(new_transaction.transaction_id, "%d", 10000000 + num_transactions + 1);
    strcpy(new_transaction.account_number, accounts[selection].account_number);
    new_transaction.amount = amount;
    
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    strftime(new_transaction.date, sizeof(new_transaction.date), "%Y-%m-%d", localTime);
    strftime(new_transaction.time, sizeof(new_transaction.time), "%I:%M %p", localTime);

	if (type == 0) {
		strcpy(new_transaction.type, "Created");
	}
	else if (type == 1) {
		strcpy(new_transaction.type, "Deleted");
	}
	else if (type == 2) {
		strcpy(new_transaction.type, "Deposit");
	}
	else if (type == 3) {
		strcpy(new_transaction.type, "Withdraw");
	}
	else if (type == 4){
		strcpy(new_transaction.type, "Sent");
	}
	else {
		strcpy(new_transaction.type, "Unknown");
	}


    fwrite(&new_transaction, sizeof(struct transaction), 1, file);
    
    if (type == 4) {
    	strcpy(new_transaction.type, "Received");
    	strcpy(new_transaction.account_number, accounts[transfer_to].account_number);
    	fwrite(&new_transaction, sizeof(struct transaction), 1, file);
	}
    
    fclose(file);
    
    transactions_size += 1;
}

void listTransactions() {
    struct transaction transactions[MAX_TRANSACTIONS];
    struct transaction account_transactions[MAX_TRANSACTIONS];
	
	FILE *file = fopen("transactions.dat", "rb");
	if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    transactions_size = fread(transactions, sizeof(struct transaction), MAX_TRANSACTIONS, file);
	
	int account_transactions_size = 0;
	for(int k = 0; k < transactions_size; k++) {
	    if (!strcmp(accounts[selection].account_number, transactions[k].account_number)) {
		    account_transactions[account_transactions_size] = transactions[k];
		    account_transactions_size++;
		}
	}

	
	int i; int j = 0;
	int page = 0; int max_page = (account_transactions_size-1)/PAGE_LENGTH;
	int item_count = account_transactions_size-1-(page*PAGE_LENGTH);
	
	while(1) {
		system("CLS");
		printLine(2);
	    printf("Transaction History for Account %s:\n", accounts[selection].account_number);
		printLine(2);
	    printf("    ID    |   TYPE    |      AMOUNT      |    DATE    |   TIME    \n");
		for(i=item_count; j<PAGE_LENGTH && i>=0 ; i--, j++) {		
    		printf(" %8s | %-10s| %-16.2lf | %-10s | %-11s\n", account_transactions[i].transaction_id, account_transactions[i].type, account_transactions[i].amount, account_transactions[i].date, account_transactions[i].time);
		}
		j = 0;
	    printLine(2);
		printf(" Page %d/%d    ", page+1, max_page+1);
		if (page > 0) {
			printf("[8] Previous Page    ");
		}
		if (page != max_page) {
			printf("[9] Next Page    ");
		}
		printf("[0] Return\n");
	    printLine(2);
		
		int choice;
		while (1) {
	        input(Int, "Enter choice: ", &choice);
	        switch (choice) {
	            case 8:
	            	if (page > 0) {	
						page--;				
						item_count = account_transactions_size-1-(page*PAGE_LENGTH);
						break;
					}
					else {
		                printf("Invalid choice.\n");
		                printLine(0);
		                continue;
					}
		            
	            case 9:
	            	if (page != max_page) {	
	            		page++;
	            		item_count = account_transactions_size-1-(page*PAGE_LENGTH);
						break;
					}
					else {
		                printf("Invalid choice.\n");
		                printLine(0);
		                continue;
					}
	            case 0:
					fclose(file);
					printLine(0);
				    newTransaction();
	                break;
	            default:
	                printf("Invalid choice.\n");
	                printLine(0);
	                continue; 
	        }
	        break;
	    }
	}
}

void listAllTransactions() {
    struct transaction transactions[MAX_TRANSACTIONS];
	
	FILE *file = fopen("transactions.dat", "rb");
	if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    transactions_size = fread(transactions, sizeof(struct transaction), MAX_TRANSACTIONS, file);

	int i; int j = 0;
	int page = 0; int max_page = (transactions_size-1)/PAGE_LENGTH;
	int item_count = transactions_size-1-(page*PAGE_LENGTH);
	
	while(1) {
		system("CLS");
		printf("------------------------------------------------------------------------------\n");
	    printf("Transaction History for All Accounts:\n");
		printf("------------------------------------------------------------------------------\n");
	    printf("    ID    |   TYPE    |      AMOUNT      |    DATE    |   TIME    |  ACCTNO.  \n");
	    for(i=item_count; j<PAGE_LENGTH && i>=0 ; i--, j++) {		
	    	printf(" %8s | %-10s| %-16.2lf | %-10s | %-9s | %-7s \n", transactions[i].transaction_id, transactions[i].type, transactions[i].amount, transactions[i].date, transactions[i].time, transactions[i].account_number);	
		}
		j = 0;
		printf("------------------------------------------------------------------------------\n");
		printf(" Page %d/%d    ", page+1, max_page+1);
		if (page > 0) {
			printf("[8] Previous Page    ");
		}
		if (page != max_page) {
			printf("[9] Next Page    ");
		}
		printf("[0] Return\n");
		printf("------------------------------------------------------------------------------\n");	
		
		int choice;
		while (1) {
	        input(Int, "Enter choice: ", &choice);
	        switch (choice) {
	            case 8:
	            	if (page > 0) {	
						page--;				
						item_count = transactions_size-1-(page*PAGE_LENGTH);
						break;
					}
					else {
		                printf("Invalid choice.\n");
		                printLine(0);
		                continue;
					}
		            
	            case 9:
	            	if (page != max_page) {	
	            		page++;
	            		item_count = transactions_size-1-(page*PAGE_LENGTH);
						break;
					}
					else {
		                printf("Invalid choice.\n");
		                printLine(0);
		                continue;
					}
	            case 0:
					fclose(file);
					printLine(0);
				    showAdminMenu();
	                break;
	            default:
	                printf("Invalid choice.\n");
	                printLine(0);
	                continue; 
	        }
	        break;
	    }
	}
}


