#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPixmap>
#include<QPen>
#include<QPainter>
#include<figure.h>
#include<circle.h>
#include<QPointF>
#include<QVector>
#include<square.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_draw_clicked();
    void on_add_circle_clicked();

    void on_add_square_clicked();

protected:
    QPainter *painter;
    QPixmap *pixmap;
    QPen *pen;
    QVector<figure *> vf;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
