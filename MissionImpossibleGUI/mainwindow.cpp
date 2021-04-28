#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"
#include "Stale.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Mission Impossible");
    setWindowIcon(QIcon(QString("Icon.png")));

    connect(&timer, &QTimer::timeout, this, &MainWindow::Kolejna_klatka);
    timer.start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);
    gra.Wyswietl_aktualna(painter);
    painter.end();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int sterowanie = 0;

    switch(e->key())
    {
        case 87:
            sterowanie = 87;
            break;
        case 83:
            sterowanie = 83;
            break;
        case 65:
            sterowanie = 65;
            break;
        case 68:
            sterowanie = 68;
            break;
    }

    if(sterowanie != 0)
    {
         gra.Do_sterowania_dla_gracza(sterowanie);
    }
}

void MainWindow::Kolejna_klatka()
{
    CGra::SCzy_koniec koniec = gra.Kolejna_klatka();
    if (koniec.czy_przegrales || koniec.czy_wygrales) {
        timer.stop();
    }
    update();
}
