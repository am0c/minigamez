#include <stdio.h>
#include <termios.h>
#include <poll.h>
#include "board.h"
#include "game.h"

static struct termios original_termios;

static
int disable_canonical()
{
    struct termios t;
    t.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, &t);
    return 0;
}

static
int restore_canonical()
{
    tcsetattr(STDIN_FILENO, &original_termios);
    return 0;
}

static
int game_input(const unsigned char ch)
{

}

void game_start()
{
    int nr, input;
    struct pollfd event;

    tcgetattr(STDIN_FILENO, &original_termios);
    disable_canonical();
    
    for (;;) {
        event.fd = stdin;
        event.events = POLLIN;
        event.revents = 0;
        
        nr = poll(event, 1, 500);
        if (nr <= 0)
            continue;

        if (event.revents == POLLIN) {
            if ((input = getchar()) == EOF)
                break;
            game_input(input);
            print_board();
        }
    }

    restore_canonical();
    return;
}
