#ifndef SHAPE_H_
#define SHAPE_H_
#include "redraw.h"
#include "redraw2.h"
#include "redraw3.h"


int ShapeEncounter(POSITION *player,POSITION *shape);
void initShapeLocation(POSITION *shape);
void getShapeLocation(POSITION *shape,POSITION *player,int i,int stage);

#endif /* SHAPE_H_ */
