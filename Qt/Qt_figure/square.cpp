#include "square.h"

square::square(int cor_x_, int cor_y_)
{
        cor_x = cor_x_;
        cor_y = cor_y_;
}
void square::draw(QPainter * painter)
{
    //QPointF points[4]{QPointF(cor_x,cor_y),QPointF(20.0,20.0),QPointF(40.0,20.0),QPointF(40.0,40.0)};
    //painter->drawPolygon(points, 4);
    painter->drawRect(cor_x,cor_y,100,100);

}

square::~square(){

}

