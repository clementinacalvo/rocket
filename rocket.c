/*
 * Rocket
 * Author: Clementina Calvo <ccalvo@itba.edu.ar>
 * Date: 11/2016
 *
 */

#include <stdio.h>
#include <unistd.h> // for usleep function

#define MAX_CONSOLE_LINES       50
#define START_SLEEP_TIME_US     300000
#define SPEED_UP_PERCENTAGE     10
#define SPEED_UP_CONSTANT       (100-SPEED_UP_PERCENTAGE)/100

const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |N|\n\
          |A|\n\
          |S|\n\
          |A|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";

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