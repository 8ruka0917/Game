#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "redraw.h"
#include "unistd.h"
#include "player.h"

void initPlayerLocation(POSITION *player){
        mvprintw(player->y, player->x, " ");
        player->y = 5;
        player->x = 5;
        mvprintw(player->y, player->x, "@");
}

void getPlayerLocation(POSITION *player, int key){
        switch(key){
                case KEY_LEFT:
                        if(0<player->x){
                                player->x = player->x-1;
                                break;
                        }
                        
                case KEY_RIGHT:
                        if(player->x < (COLS-1)){
                                player->x = player->x+1;
                                break;
                        }
                        
                case KEY_UP:
                        if(0<player->y){
                                player->y = player->y-1;
                                break;
                        }
                        
                case KEY_DOWN:
                        if(player->y < (LINES-1)){
                                player->y = player->y+1;
                                break;
                        }
                default:
                        break;
        }
}


int encounter(POSITION *player,POSITION *monster){
        if( (player->x == monster->x) && (player->y == monster->y) ){
                return 1;
        }else{
                return 0;
        }
}

void pointDisp(int stage,int score,int count){
        mvprintw(0, 1, "stage:%d", stage+1);
        mvprintw(1, 1, "score:%d", score);
        mvprintw(2, 2, "count:%3d", MAX_COUNT-count);
}

void initMonsterLocation(POSITION *monster){
        mvprintw(monster->y, monster->x, " ");
        monster->x = COLS/2;
        monster->y = LINES/2;
        mvprintw(monster->y, monster->x, "M");
}

char gameOver(){
        mvprintw(LINES/2, COLS/2-1, "GAME OVER");
        refresh();
        sleep(2);
        return 'q';
}


