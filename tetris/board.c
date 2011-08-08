#include "tetromino.h"

#define TETRIS_BOARD_STAT __brd.state
#include "board.h"

static struct board __brd;

void board_init()
{
    __brd.level = 0;
    if (init_ttr_container(__brd.container))
        BSset(BRDs_container_init);
    board_clr();
    board_queue_rnd();
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
