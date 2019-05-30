#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pixmap = new QPixmap(1200, 800);
    pixmap->fill();

    pen = new QPen(QColor("green"));

    ui->label->setPixmap(*pixmap);

    painter = new QPainter(pixmap);
    painter->setPen(*pen);
    //aqui crear el vector
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_draw_clicked()
{
    pixmap->fill();
    for (int i = 0; i< vf.size();i++) {
         vf[i]->draw(painter);
    }
    ui->label->setPixmap(*pixmap);

}

void MainWindow::on_add_circle_clicked()
{
     int r = rand() % 500 + 1;
     vf.push_back(new circle(r,r,100));
}

void MainWindow::on_add_square_clicked()
{
    int r = rand() % 500 + 1;
    vf.push_back(new square(r,r));
}
