#include <stdio.h>
#include <unistd.h> // for usleep function

#define MAX_CONSOLE_LINES       50
#define START_SLEEP_TIME_US     300000

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
        printf("\n"); // jump to bottom of console

    printf("%s", rocket);

    int j = START_SLEEP_TIME_US;
    for (i = 0; i < MAX_CONSOLE_LINES; i ++) {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
    return 0;
}