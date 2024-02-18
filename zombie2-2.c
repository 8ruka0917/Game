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
#include "shape.h"


int caughtByZombie(POSITION *player,POSITION *zombie,int zombieNum){
        int i;
        for(i=0;i<zombieNum;++i){
                if(player->x==zombie[i].x && player->y==zombie[i].y){
                        return 1;   
                }else{
                        return 0;
                }
        }
}

void initZombie(POSITION *zombie,int stage){
        int i;
        //if(1<=stage){
                for(i=0;i<stage;++i){
                        mvprintw(zombie[i].y,zombie[i].x," ");
                }
        

                for(i=0;i<stage;++i){
                        zombie[i].x=(COLS/2-1)+rand()%21-10;
                        zombie[i].y=(LINES/2-1)+rand()%21-10;

                        mvprintw(zombie[i].y,zombie[i].x,"Z");
                }
        //}
        
}

void getZombieLocation(POSITION *zombie,int i, POSITION *player){
        int a,b;
        double c,Bx,By;
        int t;
        
        a=player->x-zombie[i].x;
        b=player->y-zombie[i].y;
        c=sqrt(pow(a,2)+pow(b,2));
        Bx=2*a/c;
        By=2*b/c;

        t=rand()%2;

        zombie[i].x=zombie[i].x+(int)(Bx*t);
        zombie[i].y=zombie[i].y+(int)(By*t);
}


int getHighScore(int highScore,int score){
        if(highScore<score){
                return score;
        }else{
                return highScore;
        }
}

int loadHighScore(){
        FILE *fp;
        int score;

        fp=fopen("highscore.txt", "r");

        if(fp==NULL){
                return 0;
        }
        fscanf(fp,"%d",&score);
        fclose(fp);
        return score;
}

void saveHighScore(int score){
        FILE *fp;

        fp=fopen("highscore.txt", "w");

        if(fp==NULL){
                return;
        }
        fprintf(fp,"%d",score);
        fclose(fp);
}

void highScoreDisp(int highScore){
        mvprintw(0,(COLS/2+2)-1,"HI SCORE:%d",highScore);
}
 
