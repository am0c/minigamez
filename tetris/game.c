#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <poll.h>
#include "board.h"
#include "game.h"

static struct termios original_termios;

static
int disable_canonical()
{
    struct termios t;
    t.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
    return 0;
}

static
int restore_canonical()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
    return 0;
}

static
int game_input(const unsigned char ch)
{
    switch (ch) {
    case 'h':
        move_ttr(-1, 0);
        break;
    case 'j':
        move_ttr(0, -1);
        break;
    case 'k':
        rotate_ttr(1);
        break;
    case 'l':
        move_ttr(1, 0);
        break;
    case ' ':
        move_ttr(0, -BRD_HEIGHT);
        break;
    }
}

void game_start()
{
    int nr, input;
    struct pollfd event;

    tcgetattr(STDIN_FILENO, &original_termios);
    disable_canonical();
    board_init();
    
    for (;;) {
        event.fd = STDIN_FILENO;
        event.events = POLLIN;
        event.revents = 0;
        
        nr = poll(&event, 1, 1500);
        if (nr <= 0)
            continue;

        if (event.revents == POLLIN) {
            if ((input = getchar()) == EOF)
                break;
            game_input(input);
            board_print();
        } else {
            move_ttr(0, -1);
        }
    }

    restore_canonical();
    return;
}
