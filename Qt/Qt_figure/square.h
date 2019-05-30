#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class square : public figure
{
private:
    int cor_x,cor_y;
public:
    square(int cor_x_ = 0, int cor_y_= 0);
    ~square();
    void draw(QPainter * painter);
};

#endif // SQUARE_H
