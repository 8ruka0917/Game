#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#include "redraw.h"
#include "redraw2.h"

#define MAX_ZOMBIE 50 /* the max number of zombie */

int caughtByZombie(POSITION *player,POSITION *zombie,int zombieNum);
void initZombie(POSITION *zombie,int stage);
void getZombieLocation(POSITION *zombie,int i, POSITION *player);
int getHighScore(int highScore,int score);
int loadHighScore();
void saveHighScore(int score);
void highScoreDisp(int highScore);
#endif /* ZOMBIE_H_ */

