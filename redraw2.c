#include<stdlib.h>
#include<time.h>
#include "redraw.h"
#include<ncurses.h>
#include "redraw2.h"
#include "player.h"

void redraw2(){
        POSITION *player = (POSITION *)malloc(sizeof(POSITION));
        POSITION *monster = (POSITION *)malloc(sizeof(POSITION));

        int count = 0, stage = 0, score = 0, key = 'h';


        initscr();
        noecho();
        cbreak();
        curs_set(0);
        timeout(500);

        keypad(stdscr,true);

        initMonsterLocation(monster);

        initPlayerLocation(player);

        while (key != 'q'){
                count = count + 1;
                pointDisp(stage, score, count);
                mvprintw(monster->y, monster->x, " ");
                getMonsterLocation(monster);
                mvprintw(monster->y, monster->x, "M");
                mvprintw(player->y, player->x, " ");
                getPlayerLocation(player, key);
                mvprintw(player->y, player->x, "@");
                refresh();
                if(count == MAX_COUNT){
                     key=gameOver();
                }else if(encounter(player,monster) == 1){
                     sleep(2);
                     stage = stage + 1;
                     score = score + (MAX_COUNT - count);
                     count = 0;
                     initPlayerLocation(player);
                     initMonsterLocation(monster);
                }else{
                        key = getch();
                }       
        }
        endwin();
}


