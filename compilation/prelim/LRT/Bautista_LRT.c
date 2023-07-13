#include <stdio.h>
#include "glencrypt.h"

int getFare(int ticketType, int origin, int destination);
int getTicketType();
int getStation(int mode);
void printMenu();

int main() {
    int ticketType;
    int origin, destination;
    int fare;

    ticketType = getTicketType();
    printMenu();
    origin = getStation(0);
    destination = getStation(1);

    fare = getFare(ticketType, origin, destination);
    printf("Your total fare is: Php %d\n", fare);
    waitEnter();
    return 0;
}

int getTicketType() {
    int ticketType;
    while(1) {
        printf("LRT-1 Fare Calculator\n");
        printf("----------------------------------------\n");
        printf("[1] Single Journey Ticket\n");
        printf("[2] Stored Value Card\n");
        printf("[0] Return\n");
        printf("----------------------------------------\n");
        input(Int, "Please choose ticket type: ", &ticketType);
        if (ticketType == 1 || ticketType == 2) {
            return ticketType;
        }
        else if (ticketType == 0) {
            exit(0);
        }
        else {
            printf("Invalid ticket type. Please try again.\n");
            waitEnter();
        }
    }
}

int getStation(int mode) {
    int origin, destination;
    while(1) {
        if (mode == 0) {
            input(Int, "Choose your origin: ", &origin);
            return origin;
        }
        else {
            printf("Choose your destination: ");
            input(Int, "Choose your origin: ", &destination);
            if (origin != destination) {
                printf("----------------------------------------\n");
                return destination;
            }
            else {
                printf("Origin and destination cannot be the same. Please try again.\n");
                printf("----------------------------------------\n");
            }
        }
    }
}

int getFare(int ticketType, int origin, int destination) {
    int sjtFares[20][20] = {
        {0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30, 30, 30},
        {15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30, 30},
        {15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30},
        {15, 15, 15, 0, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30},
        {15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30},
        {15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30},
        {20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30},
        {20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 30, 30},
        {20, 20, 20, 20, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 20, 20, 20, 20, 30},
        {20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 20, 20, 20, 30},
        {20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 20, 20, 30},
        {20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20},
        {30, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 30, 30, 30, 30, 30, 30, 30},
        {30, 30, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 30, 30, 30, 30, 30, 30},
        {30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 0, 30, 30, 30, 30, 30},
        {30, 30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 0, 30, 30, 30, 30},
        {30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 0, 30, 30, 30},
        {30, 30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 30, 30},
        {30, 30, 30, 30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 20, 20, 15, 15, 15, 0, 30},
        {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 20, 15, 15, 0}
    };
    int svcFares[20][20] = {
        {11, 12, 13, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21, 21, 22, 23, 24, 25, 27, 29},
        {12, 11, 12, 13, 14, 15, 15, 16, 17, 18, 19, 19, 20, 21, 22, 22, 23, 24, 27, 29},
        {13, 12, 11, 12, 13, 14, 14, 15, 16, 17, 18, 18, 19, 20, 21, 21, 22, 23, 26, 28},
        {13, 13, 12, 11, 12, 13, 14, 14, 16, 16, 17, 18, 18, 19, 20, 21, 22, 23, 25, 27},
        {14, 14, 13, 12, 11, 12, 13, 13, 15, 15, 16, 17, 17, 18, 19, 20, 21, 22, 24, 26},
        {15, 15, 14, 13, 12, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 23, 25},
        {16, 15, 14, 14, 13, 12, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 22, 24},
        {17, 16, 15, 14, 13, 13, 12, 11, 12, 13, 14, 14, 15, 16, 17, 17, 18, 19, 22, 23},
        {18, 17, 16, 16, 15, 14, 13, 12, 11, 12, 12, 13, 14, 14, 15, 16, 17, 18, 20, 22},
        {19, 18, 17, 16, 15, 14, 14, 13, 12, 11, 12, 12, 13, 14, 15, 15, 16, 17, 20, 22},
        {19, 19, 18, 17, 16, 15, 14, 14, 12, 12, 11, 12, 12, 13, 14, 15, 15, 17, 19, 21},
        {20, 19, 18, 18, 17, 16, 15, 14, 13, 12, 12, 11, 12, 12, 13, 14, 15, 16, 18, 20},
        {21, 20, 19, 18, 17, 16, 16, 15, 14, 13, 12, 12, 11, 12, 13, 13, 14, 15, 18, 20},
        {21, 21, 20, 19, 18, 17, 16, 16, 14, 14, 13, 12, 12, 11, 12, 13, 14, 15, 17, 19},
        {22, 22, 21, 20, 19, 18, 17, 17, 15, 15, 14, 13, 13, 12, 11, 12, 13, 14, 16, 18},
        {23, 22, 21, 21, 20, 19, 18, 17, 16, 15, 15, 14, 13, 13, 12, 11, 12, 13, 15, 17},
        {24, 23, 22, 22, 21, 20, 19, 18, 17, 16, 15, 15, 14, 14, 13, 12, 11, 12, 15, 16},
        {25, 24, 23, 23, 22, 21, 20, 19, 18, 17, 17, 16, 15, 15, 14, 13, 12, 11, 13, 15},
        {27, 27, 26, 25, 24, 23, 22, 22, 20, 20, 19, 18, 18, 17, 16, 15, 15, 13, 11, 13},
        {29, 29, 28, 27, 26, 25, 24, 23, 22, 22, 21, 20, 20, 19, 18, 17, 16, 15, 13, 11}
    };
    int fare;
    if (ticketType == 1) {
        fare = sjtFares[origin][destination];
    } else if (ticketType == 2) {
        fare = svcFares[origin][destination];
    }
    return fare;
}

void printMenu() {
    system("cls");
    printf("----------------------------------------\n");
    printf("[0] Baclaran\n");
    printf("[1] EDSA\n");
    printf("[2] Libertad\n");
    printf("[3] Gil Puyat\n");
    printf("[4] Vito Cruz\n");
    printf("[5] Quirino\n");
    printf("[6] Pedro Gil\n");
    printf("[7] United Nations\n");
    printf("[8] Central Terminal\n");
    printf("[9] Carriedo\n");
    printf("[10] Doroteo Jose\n");
    printf("[11] Bambang\n");
    printf("[12] Tayuman\n");
    printf("[13] Blumentritt\n");
    printf("[14] Abad Santos\n");
    printf("[15] R. Papa\n");
    printf("[16] 5th Avenue\n");
    printf("[17] Monumento\n");
    printf("[18] Balintawak\n");
    printf("[19] Roosevelt\n");
    printf("----------------------------------------\n");
}