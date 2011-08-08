#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "game.h"
#include "timer.h"

int main()
{
    pid_t timer;
    timer = fork();
    
    if (timer < 0) {
        /* error */
    } else if (timer) {
        start_game();
    } else {
        start_timer();
    }

    return 0;
}

