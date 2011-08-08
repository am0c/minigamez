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

struct block board_tbl[BRD_HEIGHT][BRD_HEIGHT];
struct tetromino queue[BRD_QUEUE_SIZE];

#endif  /* TETRIS_BOARD_H */