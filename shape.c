#include<stdlib.h>
#include<time.h>
#include "redraw.h"
#include "redraw2.h"
#include<ncurses.h>
#include "player.h"
#include "zombie.h"
#include<math.h>
#include "redraw3.h"
#include<stdio.h>
#include "redraw4.h"
#include "shape.h"

int ShapeEncounter(POSITION *player,POSITION *shape){
        if( (player->x==shape->x) && (player->y==shape->y) ){
                return 1;
        }else{
                return 0;
        }
}


void initShapeLocation(POSITION *shape){
        mvprintw(shape->y,shape->x," ");
        shape->y=10;
        shape->x=10;
        mvprintw(shape->y,shape->x,"#");
}


void getShapeLocation(POSITION *shape,POSITION *zombie,int i,int stage){

        if(0<shape->x && shape->x<COLS-1){
                for(i=0;i<stage;++i){
                        shape->x=zombie[i].x+5;
                }
                
        }
        if(0<shape->y && shape->y<LINES-1){
                for(i=0;i<stage;++i){
                        shape->y=zombie[i].y+5;
                }
                
        }
}

