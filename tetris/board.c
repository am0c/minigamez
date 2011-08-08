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

struct tetromino *board_queue(ttr_type type)
{
    return &__brd.container[__brd.queue[0] = type];
}

struct tetromino *board_queue_rnd()
{
    return board_queue(rand() % TTRt_CNT);
}

struct tetromino *board_dequeue()
{
    struct tetromino *pop = &__brd.onboard[type];

    clone_ttr(__brd.container, pop, __brd.queue[0]);
    board_queue_rnd();

    return pop;
}
