#ifndef PLAYER_H_
#define PLAYER_H_
#include "redraw.h"

#define MAX_COUNT 600 /* initial score */

void initPlayerLocation(POSITION *player);
void getPlayerLocation(POSITION *player,int key);
int encounter(POSITION *player,POSITION *monster);
void initMonster(POSITION *monster);
void pointDisp(int stage,int score,int count);
char gameOver();
#endif /* PLAYER_H_ */
