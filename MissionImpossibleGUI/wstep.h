#ifndef WSTEP_H
#define WSTEP_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "mainwindow.h"
#include "help.h"

namespace Ui {
class Wstep;
}

class Wstep : public QDialog
{
    Q_OBJECT
    
public:
    explicit Wstep(QWidget *parent = 0);
    ~Wstep();
    
private:
    Ui::Wstep *ui;

    MainWindow *glowne_okno;
    Help* help;

    QPushButton *latwy;
    QPushButton *trudny;
    QPushButton *zasady_gry;

    QLabel *przywitanie;
    QLabel *wybor_poziomu;
    QLabel *kto_wykonal;

    void Pressed_latwy();
    void Pressed_trudny();
    void Pressed_zasady();
};

#endif // WSTEP_H
