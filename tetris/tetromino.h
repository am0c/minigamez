#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H
#include <stdint.h>

typedef enum {
    TTRt_I = 0,
    TTRt_J,
    TTRt_L,
    TTRt_O,
    TTRt_S,
    TTRt_T,
    TTRt_Z,
    TTRt_CNT,
} ttr_type;

struct tetromino {
    int x;
    int y;
    int rotation;
    int color;
    ttr_type type;
    uint16_t binary[4];
};

int init_ttr_container(void);
struct tetromino *init_ttr(int type);
int ttr_to_color(ttr_type type);

#endif  /* TETRIS_TETROMINO_H */
