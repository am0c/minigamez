#include "tetromino.h"

static const
char *tetromino_res[7][4] = {
    {
        "...."
        "####"
        "...."
        "....",

        ".#.."
        ".#.."
        ".#.."
        ".#..",
    },
    {
        "...."
        ".##."
        ".#.."
        ".#..",

        "...."
        ".#.."
        ".###"
        "....",

        "..#."
        "..#."
        ".##."
        "....",

        "...."
        "###."
        "..#."
        "....",
    },
    {
        "...."
        ".##."
        "..#."
        "..#.",

        "...."
        "..#."
        "###."
        "....",

        ".#.."
        ".#.."
        ".##."
        "....",
        
        "...."
        ".###"
        ".#.."
        "....",
    },
    {
        "...."
        ".##."
        ".##."
        "....",
    },
    {
        "...."
        ".#.."
        ".##."
        "..#.",

        "...."
        "..##"
        ".##."
        "....",
    },
    {
        "...."
        ".#.."
        "###."
        "....",

        "...."
        ".#.."
        ".##."
        ".#..",

        "...."
        "...."
        "###."
        ".#..",

        "...."
        ".#.."
        "##.."
        ".#..",
    },
    {
        "...."
        ".#.."
        "##.."
        "#...",

        "...."
        "##.."
        ".##."
        "....",
    },
};

static const
int color_res[] = {
    0, /* TTRc_I */
    0, /* TTRc_J */
    0, /* TTRc_L */
    0, /* TTRc_O */
    0, /* TTRc_S */
    0, /* TTRc_T */
    0, /* TTRc_Z */
    0, /* TTRc_BLANK */
};

static struct tetromino ttr_container[TTRt_CNT];
static struct tetromino ttr_onboard[TTRt_CNT];

int init_ttr_container()
{
    static int is_init = 0;
    struct tetromino *t;
    int rotation, rcnt;
    int type, i;
    char *str;
    
    if (is_init)
        return 0;

    for (type = 0; type < TTRt_CNT; type++) {
        t = ttr_container[type];
        t.x = 4;
        t.y = 20;
        t.rotation = 0;
        t.color = ttr_to_color[type];
        t.type = type;
        t.binary = 0;

        for (rcnt = 0, rotation = 0; rotation < 4; rotation++) {
            str = tetromino_res[type][rotation];
            if (!rcnt || !str) {
                rcnt = rotation;
                t.binary[rotation] = t.binary[rotation % rcnt];
            }
            else for (i = 15; i >= 0; i--, str++) {
                t.binary[rotation] |= (str == '#' ? 1 : 0) << i;
            }
        }
    }

    return ++is_init;
}

struct tetromino *init_ttr(ttr_type type)
{
    struct tetromino *ttr = &ttr_onboard[type];
    
    init_ttr_container();
    *ttr = ttr_container[type];
    
    return ttr;
}

int ttr_to_color(ttr_type type)
{
    return color_res[type];
}
