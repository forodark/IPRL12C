#include <stdio.h>
#include <string.h>
#include "glencrypt.h"

typedef struct {
    int acctNo;
    char pin[7];
    double balance;
    char name[20];
    char status[10];
} Account;

int main()
{
//    Account accounts[] = {
//        {1001, "000000", 5000.00, "Glen", "Active"},
//        {1002, "123456", 5000.00, "Angelo", "Locked"},
//        {1003, "2468", 5000.00, "Yui", "Active"},
//        {1004, "030918", 99999.00, "Happy", "Active"},
//        {1005, "0427", 0.00, "Forodark", "Active"}
//    };
//
//    printTable(5, 5,
//               "ACCTNO.", "%d",
//               "PIN", "%s",
//               "BALANCE", "%.2f",
//               "NAME", "%s",
//               "STATUS", "%s",
//               &accounts[0].acctNo, accounts[0].pin, &accounts[0].balance, accounts[0].name, accounts[0].status,
//               &accounts[1].acctNo, accounts[1].pin, &accounts[1].balance, accounts[1].name, accounts[1].status,
//               &accounts[2].acctNo, accounts[2].pin, &accounts[2].balance, accounts[2].name, accounts[2].status,
//               &accounts[3].acctNo, accounts[3].pin, &accounts[3].balance, accounts[3].name, accounts[3].status,
//               &accounts[4].acctNo, accounts[4].pin, &accounts[4].balance, accounts[4].name, accounts[4].status);
//

	int number = 2;
	char *name = printVarName(number);
	printf("%s", name)

    return 0;
}
