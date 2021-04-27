#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "cgra.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent * e);
    
private:
    Ui::MainWindow *ui;
    CGra gra;
    QTimer timer;

    void Kolejna_klatka();
};

#endif // MAINWINDOW_H
