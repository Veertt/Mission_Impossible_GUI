#include "wstep.h"
#include "ui_wstep.h"

Wstep::Wstep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wstep)
{
    ui->setupUi(this);
    setWindowTitle("Mission Impossible");
    setWindowIcon(QIcon(QString("Icon.png")));
    setFixedSize(300,300);

    latwy = new QPushButton("Łatwy",this);
    latwy->setGeometry(QRect(QPoint(40,80),QSize(220,40)));
    connect(latwy,&QPushButton::pressed,this,&Wstep::Pressed_latwy);

    trudny = new QPushButton("Trudny",this);
    trudny->setGeometry(QRect(QPoint(40,130),QSize(220,40)));
    connect(trudny,&QPushButton::pressed,this,&Wstep::Pressed_trudny);

    zasady_gry = new QPushButton("Naciśnij mnie, aby przeczytać zasady gry",this);
    zasady_gry->setGeometry(QRect(QPoint(40,200),QSize(220,40)));
    connect(zasady_gry,&QPushButton::pressed,this,&Wstep::Pressed_zasady);

    QFont f("Arial",15);
    przywitanie = new QLabel("Witaj w Mission Impossible!",this);
    przywitanie->setGeometry(QRect(QPoint(30,1),QSize(250,50)));
    przywitanie->setFont(f);

    f.setPointSize(12);
    wybor_poziomu = new QLabel("Wybierz poziom gry:",this);
    wybor_poziomu->setGeometry(QRect(QPoint(80,40),QSize(200,50)));
    wybor_poziomu->setFont(f);

    f.setPointSize(10);
    kto_wykonal = new QLabel("Wykonał: Bartłomiej Guś gr.IPAUT-161",this);
    kto_wykonal->setGeometry(QRect(QPoint(1,260),QSize(300,50)));
    kto_wykonal->setFont(f);

}

void Wstep::Pressed_latwy()
{
    this->hide();
    glowne_okno = new MainWindow();
    glowne_okno->Graj_w_zaleznosci_od_poziomu(0,this);
    glowne_okno->show();
}

void Wstep::Pressed_trudny()
{
    this->hide();
    glowne_okno = new MainWindow();
    glowne_okno->Graj_w_zaleznosci_od_poziomu(1,this);
    glowne_okno->show();
}

void Wstep::Pressed_zasady()
{
    help = new Help();
    help->show();
}

Wstep::~Wstep()
{
    delete ui;
}

