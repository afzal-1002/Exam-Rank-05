#include "life.h"

int main(int argc, char **argv)
{
    if(argc != 4)   
        return 1;
    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int n = atoi(argv[3]);

    if(w <= 0 || h <= 0 || n < 0)
        return 1;
    char *grid = calloc(w * h, sizeof(char));
    char *next = malloc(w * h);
    if(!grid || !next)
    {
        free(grid);
        free(next);
        return 1;
    }
    int px = 0;
    int py = 0;
    int pen = 0;
    char ch;
    while(read(0, &ch, 1) == 1)
    {
        if(ch == 'w' && py > 0)
            py--;
        else if(ch == 's' && py < h -1)
            py++;
        else if(ch == 'a' && px > 0)
            px--;
        else if(ch == 'd' && px < w - 1)
            px++;
        else if(ch == 'x')
            pen = !pen;
        if(pen)
            grid[py * w + px] = 1;
    }
    while(n--)
    {
        for(int y = 0; y < h; y++)
        {
            for(int x = 0; x < w; x++)
            {
                int neighbour = 0;
                for(int dy = -1; dy <= 1; dy++)
                {
                    for(int dx = -1; dx <= 1; dx++)
                    {
                        if(dx == 0 && dy == 0)
                            continue;
                        int nx = x + dx;
                        int ny = y + dy;

                        if(nx >= 0 && nx < w && ny >= 0 && ny < h)
                        {
                            neighbour += grid[ny * w + nx];
                        }
                    }
                }
                if(grid[y * w + x])
                {
                    next[y * w + x] = (neighbour == 2 || neighbour == 3);
                }
                else
                {
                    next[y * w + x] = (neighbour == 3);
                }
            }
        }
        char *temp = grid;
        grid = next;
        next = temp;
    }
    for(int y = 0; y < h ; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(grid[y * w + x])
                putchar('O');
            else 
                putchar(' ');
        }
        putchar('\n');
    }
    free(grid);
    free(next);
    return 0;
}
