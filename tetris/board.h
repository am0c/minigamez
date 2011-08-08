#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H
#include "tetromino.h"

#define BRD_HEIGHT      20
#define BRD_WIDTH       10
#define BRD_QUEUE_SIZE  1

#define BRDf_MENU 0x0100
#define BRDf_PMSG 0x0200
#define BRDf_STOP 0x0400
#define BRDf_PLAY 0x0800
#define BRDf_FAIL 0x1000

#define BRDp_FALL 0x0001
#define BRDp_CLRD 0x0002
#define BRDp_NOOP 0x0004

#ifdef TETRIS_BOARD_STAT
# define Bstat (TETRIS_BOARD_STAT)
# define BSset(flag)  Bstat |= (flag)
# define BSclr(flag)  Bstat &= ~(flag)
# define BSget(flag)  (Bstat & (flag))
#endif

#define BRDs_container_init 0x00010000

struct block {
    enum blk_type {
        blk_empty,
        blk_ttr,
    } type;
    int color;
};

struct board {
    int level;
    uint32 state;
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
