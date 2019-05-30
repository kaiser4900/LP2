#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class circle : public figure
{
private:
    int cor_x,cor_y, radio;
public:
    circle(int cor_x_ = 0, int cor_y_= 0, int radio_ = 0);
    ~circle();
    void draw(QPainter * painter);

};

#endif // CIRCLE_H
