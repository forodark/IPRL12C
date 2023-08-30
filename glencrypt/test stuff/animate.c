#include <stdio.h>
#include "glencrypt.h"

typedef struct {
    char* frame;
    int delay;
} animation;

typedef struct {
    char* frame;
} animationfps;


#define END_ANIMATION NULL

animation test[] = {
    {"Test 1", 500},
    {"Test 2", 500},
    {"Test 3", 500},
    {"Test 4", 500},
    {"Test 5", 500},
    {"Test 6", 500},
    {"Test 7", 500},
    {"Test 8", 500},
    {"Test 9", 500},
    {"Test 10", 500},
    {"Test 11", 1000},
    {"Test 12", 1000},
    {"Test 13", 1000},
    {"Test 14", 1000},
    {"Test 15", 1000},
    {"Test 16", 1000},
    {"Test 17", 1000},
    {"Test 18", 1000},
    {"Test 19", 1000},
    {"Test 20", 1000},
    END_ANIMATION
};

void animatefps(animationfps* animation, int fps) {
    system("cls");
    int delay = 1000000/fps;
    for(int i = 0; animation[i].frame != END_ANIMATION; i++) {
        printf("%s\n", animation[i].frame);
        usleep(delay);
        system("cls");
    }
}

void animate(animation* animation) {
    system("cls");
    for(int i = 0; animation[i].frame != END_ANIMATION; i++) {
        printf("%s\t", animation[i].frame);
        int delay = animation[i].delay*1000;
        usleep(delay);
        system("cls");
    }
}

void animateline(animation* animation


int main()
{
    // animate(test);

    printf("test1\ntest2");
    sleep(1);
    printf("\rtest3\ntest4");
    return 0;
}
