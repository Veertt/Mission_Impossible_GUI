#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDialog>
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
    virtual void paintEvent(QPaintEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

    void Graj_w_zaleznosci_od_poziomu(int level, QDialog *wstep);
    
private:
    Ui::MainWindow *ui;
    QDialog *menu;
    CGra gra;
    QTimer timer;
    int sterowanie;

    void Kolejna_klatka();
};

#endif // MAINWINDOW_H
