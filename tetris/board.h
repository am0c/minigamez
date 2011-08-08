#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H
#include "tetromino.h"

#define BRD_HEIGHT      20
#define BRD_WIDTH       10
#define BRD_QUEUE_SIZE  1

struct block {
    enum blk_type {
        blk_empty,
        blk_ttr,
    } type;
    int color;
};

struct board {
    int level;
    int container_init;
    struct block board_tbl[BRD_HEIGHT][BRD_HEIGHT];
    ttr_type queue[BRD_QUEUE_SIZE];
    ttr_container container;
    ttr_container onboard;
};

void board_init();
void board_clr();

struct tetromino *board_queue(ttr_type type);
struct tetromino *board_queue_rnd(void);
struct tetromino *board_dequeue(void);

#endif  /* TETRIS_BOARD_H */
