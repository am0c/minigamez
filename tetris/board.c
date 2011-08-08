#include "board.h"
#include "tetromino.h"

static struct board __brd;

void board_init()
{
    init_ttr_container(__brd.container);
    board_clr();
}

void board_clr()
{
    int x, y;
    for (y = 0; y < 20; y++)
        for (x = 0; x < 10; x++)
            __brd.type = blk_empty;
}

