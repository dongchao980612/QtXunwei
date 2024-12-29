#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("智能家居控制中心");
    this->lightOn = false;
    this->switchOn = false;

    qDebug() << (lightOn ? "此时灯的状态的开启" : "此时灯的状态的关闭");
    qDebug() << (switchOn ? "此时开关的状态的开启" : "此时开关的状态的关闭");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_tuichu_clicked()
{
    this->close();
    emit(MainWindow_exit());
}


void MainWindow::on_pushButton_light_clicked()
{

    if (lightOn)
    {
        qDebug() << (lightOn ? "此时灯的状态的开启" : "此时灯的状态的关闭");
        ui->pushButton_light->setIcon(QIcon(":/pic/电灯-关.png"));
        lightOn = !lightOn;
    }
    else
    {
        qDebug() << (lightOn ? "此时灯的状态的开启" : "此时灯的状态的关闭");
        ui->pushButton_light->setIcon(QIcon(":/pic/电灯-开.png"));
        lightOn = !lightOn;
    }
}


void MainWindow::on_pushButton_switch_clicked()
{

    if (switchOn)
    {
        qDebug() << (switchOn ? "此时开关的状态的开启" : "此时开关的状态的关闭");
        ui->pushButton_switch->setIcon(QIcon(":/pic/开关-关.png"));
        switchOn = !switchOn;
    }
    else
    {
        qDebug() << (switchOn ? "此时开关的状态的开启" : "此时开关的状态的关闭");
        ui->pushButton_switch->setIcon(QIcon(":/pic/开关-开.png"));
        switchOn = !switchOn;
    }
}

