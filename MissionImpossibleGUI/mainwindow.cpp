#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

void MainWindow::Kolejna_klatka()
{
    CGra::SCzy_koniec koniec = gra.Kolejna_klatka();
    if (koniec.czy_przegrales || koniec.czy_wygrales) {
        timer.stop();
    }
    update();
}
