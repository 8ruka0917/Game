#include<stdlib.h>
#include<time.h>
#include "redraw.h"
#include<ncurses.h>
#include "redraw2.h"
#include "player.h"
#include "redraw3.h"
#include "zombie.h"
#include "redraw4.h"
#include "shape.h"

void redrawR14(){
        POSITION *player=(POSITION *)malloc(sizeof(POSITION));
        POSITION *monster=(POSITION *)malloc(sizeof(POSITION));
        POSITION zombie[MAX_ZOMBIE];
        POSITION *shape=(POSITION *)malloc(sizeof(POSITION));

        int count=0,stage=1,score=0,highScore=0,key='h';

        srand((unsigned)time(NULL));

        initscr();
        noecho();
        cbreak();
        curs_set(0);
        timeout(500);

        keypad(stdscr,true);

        initMonsterLocation(monster);

        initPlayerLocation(player);

        initZombie(zombie,stage);

        initShapeLocation(shape);

        highScore=loadHighScore();

        while (key!='q'){
                int i;
                count=count+1;

                int zombieNum=stage;

                highScore=getHighScore(highScore,score);
                highScoreDisp(highScore);
                pointDisp(stage-1,score,count);
                mvprintw(monster->y,monster->x," ");
                getMonsterLocation(monster);
                mvprintw(monster->y,monster->x,"M");
                //if(1<=stage){
                        for(i=0;i<stage;++i){
                                mvprintw(zombie[i].y,zombie[i].x," ");
                                getZombieLocation(zombie,i,player);
                                mvprintw(zombie[i].y,zombie[i].x,"Z");
                        }
                //}
                
                mvprintw(player->y,player->x," ");
                getPlayerLocation(player,key);
                mvprintw(player->y,player->x,"@");

                mvprintw(shape->y,shape->x," ");
                getShapeLocation(shape,zombie,i,stage);
                mvprintw(shape->y,shape->x,"#");

                refresh();

                
                if(count==MAX_COUNT){
                     key=gameOver();
                     saveHighScore(score);
                }else if(encounter(player,monster)==1){
                     sleep(2);
                     stage=stage+1;
                     score=score+(MAX_COUNT-count);
                     count=0;
                     initZombie(zombie,stage);
                     initPlayerLocation(player);
                     initMonsterLocation(monster);
                     initShapeLocation(shape);
                }else if(ShapeEncounter(player,shape)==1){
                        sleep(2);
                        if(count-100<MAX_COUNT){
                                count=count-100;
                        }else{
                                count=MAX_COUNT;
                        }
                }else if(caughtByZombie(player,zombie,zombieNum)==1){
                     key=gameOver();
                     saveHighScore(score);
                }else{
                        key=getch();
                }       
        }
        free(monster);
        free(player);
        free(shape);
        endwin();
}

