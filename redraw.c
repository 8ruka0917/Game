#include<stdlib.h>
#include<time.h>
#include "redraw.h"
#include<ncurses.h>


void getMonsterLocation(POSITION *monster){
        int dx, dy;
        dx = rand()%3-1;
        dy = rand()%3-1;

        if( (0 < monster->x && dx < 0) || (monster->x < COLS-1 && dx > 0) ){
                monster->x = monster->x+dx;
        }
        if( (0<monster->y && dy < 0) || (monster->y < LINES-1 && dy > 0) ){
                monster->y = monster->y+dy;
        }
}



void redraw(){
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        timeout(100);

        POSITION *monster;

        srand((unsigned)time(NULL));

        monster->x = COLS/2;
        monster->y = LINES/2;

        char ch;

        while (ch != 'q'){
                mvprintw(monster->y, monster->x, " ");
                getMonsterLocation(monster);
                mvprintw(monster->y, monster->x, "M");
                ch=getch();
                refresh();
        }
        endwin();
}


