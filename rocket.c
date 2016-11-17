/*
 * Rocket
 * Author: Clementina Calvo <ccalvo@itba.edu.ar>
 * Date: 11/2016
 *
 */

#ifdef _WIN32
   #error "This program is only targeted at Linux systems"
#endif

#include <stdio.h>
#include <unistd.h> // for usleep function

#ifndef ROCKET
 #error No rocket defined
#else
    #if   ROCKET == NASA_ROCKET
     #include "nasa_rocket.h"
    #elif ROCKET == FAT_ROCKET
     #include "fat_rocket.h"
    #elif ROCKET == LARGE_ROCKET
     #include "large_rocket.h"
    #else
     #error Unknown rocket
    #endif
 #endif //ndef ROCKET

#define MAX_CONSOLE_LINES       50
#define START_SLEEP_TIME_US     300000
#define SPEED_UP_PERCENTAGE     10
#define SPEED_UP_CONSTANT       (100-SPEED_UP_PERCENTAGE)/100


int main()
{
    int i;
    for (i = 0; i < MAX_CONSOLE_LINES; i ++)
        printf("\n");                       // jump to bottom of console

    printf("%s", rocket);

    int j = START_SLEEP_TIME_US;
    for (i = 0; i < MAX_CONSOLE_LINES; i ++) {
        usleep(j);                          // move faster and faster,
        j = (int)(j * SPEED_UP_CONSTANT);   // so sleep less each time
    }
    return 0;
}