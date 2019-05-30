#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QString>
#include <QPoint>

class figure
{
protected:

public:
    virtual ~figure();
    virtual void draw(QPainter *painter) = 0;
};

#endif // FIGURE_H
