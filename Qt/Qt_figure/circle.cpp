#include "circle.h"

circle::circle(int cor_x_, int cor_y_, int radio_)
{
    radio = radio_;
    cor_x = cor_x_;
    cor_y = cor_y_;
}

void circle::draw(QPainter * painter)
{
    painter->drawEllipse(cor_x,cor_y,100,100);
}

circle::~circle(){

}
