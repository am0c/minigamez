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

int init_ttr_container(ttr_container ttr_ct)
{
    struct tetromino *t;
    int rotation, rcnt;
    int type, i;
    char *str;
    
    for (type = 0; type < TTRt_CNT; type++) {
        t = ttr_ct[type];
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
    
    return 1;
}

struct tetromino *clone_ttr(ttr_container ttr_ct, struct tetromino *ttr, ttr_type type)
{
    init_ttr_container(ttr_ct);
    *ttr = ttr_ct[type];
    return ttr;
}

ttr_color ttr_to_color(ttr_type type)
{
    if (type <= TTRt_CNT)
        return ttr_color[type];
    else
        return 0;
}
