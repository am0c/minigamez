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

typedef int ttr_color;
const ttr_color ttr_color_tbl[] = {
    [TTRt_I] = 0,
    [TTRt_J] = 0,
    [TTRt_L] = 0,
    [TTRt_O] = 0,
    [TTRt_S] = 0,
    [TTRt_T] = 0,
    [TTRt_Z] = 0,
    [TTRt_BLANK] = 0,
};

struct tetromino {
    int x;
    int y;
    int rotation;
    ttr_color color;
    ttr_type type;
    uint16_t binary[4];
};

int init_ttr_container(void);
struct tetromino *init_ttr(int type);
ttr_color ttr_to_color(ttr_type type);

#endif  /* TETRIS_TETROMINO_H */
