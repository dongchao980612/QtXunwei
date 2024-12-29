#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("串口调试助手");
    this->setFixedSize(800, 500);
    serial = new QSerialPort(this);
    Init_ui();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init_ui()
{

    ui->plainTextEdit_receive->setReadOnly(true);
    ui->pushButton_open->setEnabled(true);
    ui->pushButton_close->setEnabled(false);
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_clear->setEnabled(false);
    ui->lineEdit_send->setEnabled(false);

    ui->comboBox_Port->setEnabled(true);
    ui->comboBox_BaudRate->setEnabled(true);
    ui->comboBox_DataBits->setEnabled(true);
    ui->comboBox_StopBits->setEnabled(true);
    ui->comboBox_Parity->setEnabled(true);

    // 添加可用串口
    for (const QSerialPortInfo &portInfo : QSerialPortInfo::availablePorts())
    {
        ui->comboBox_Port->addItem(portInfo.portName());
    }

    // 添加波特率选项
    const int baudRates[] =
    {
        1200, 2400, 4800, 9600,
        19200, 38400, 57600, 115200
    };
    for (int baudRate : baudRates)
    {
        ui->comboBox_BaudRate->addItem(QString::number(baudRate), baudRate);
    }
    ui->comboBox_BaudRate->setCurrentIndex(3); // 设置默认波特率为9600

    // 添加数据位选项
    const int dataBits[] = {5, 6, 7, 8};
    for (int dataBit : dataBits)
    {
        ui->comboBox_DataBits->addItem(QString::number(dataBit), dataBit);
    }
    ui->comboBox_DataBits->setCurrentIndex(3); // 设置默认数据位为8

    // 添加停止位选项
    const int stopBits[] = {1, 2};
    for (int stopBit : stopBits)
    {
        ui->comboBox_StopBits->addItem(QString::number(stopBit), stopBit);
    }
    ui->comboBox_StopBits->setCurrentIndex(0); // 设置默认停止位为1

    // 添加奇偶校验选项
    const QSerialPort::Parity parityOptions[] =
    {
        QSerialPort::NoParity,
        QSerialPort::OddParity,
        QSerialPort::EvenParity,
        QSerialPort::MarkParity,
        QSerialPort::SpaceParity
    };
    const QStringList parityNames =
    {
        "None", "Odd", "Even", "Mark", "Space"
    };

    for (int i = 0; i < sizeof(parityOptions) / sizeof(parityOptions[0]); ++i)
    {
        ui->comboBox_Parity->addItem(parityNames[i], parityOptions[i]);
    }
    ui->comboBox_Parity->setCurrentIndex(0); // 设置默认奇偶校验为无





}

void MainWindow::on_pushButton_open_clicked()
{
    // 获取串口名称
    QString portName = ui->comboBox_Port->currentText();

    // 配置串口对象
    serial->setPortName(portName);
    serial->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->comboBox_BaudRate->currentData().toInt()));
    serial->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboBox_DataBits->currentData().toInt()));
    serial->setParity(static_cast<QSerialPort::Parity>(ui->comboBox_Parity->currentData().toInt()));
    serial->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboBox_StopBits->currentData().toInt()));
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // 尝试打开串口
    if (serial->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "提示", "串口打开成功");
        // 启用发送和清除按钮
        ui->pushButton_open->setEnabled(false);
        ui->pushButton_close->setEnabled(true);
        ui->pushButton_send->setEnabled(true);
        ui->pushButton_clear->setEnabled(true);
        ui->lineEdit_send->setEnabled(true);

        ui->comboBox_Port->setEnabled(false);
        ui->comboBox_BaudRate->setEnabled(false);
        ui->comboBox_DataBits->setEnabled(false);
        ui->comboBox_StopBits->setEnabled(false);
        ui->comboBox_Parity->setEnabled(false);

        // 连接信号和槽
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead_slot);

    }
    else
    {
        // 打开失败，提示用户
        QMessageBox::critical(this, "串口打开失败", "无法打开串口: " + portName);

    }
}


void MainWindow::on_pushButton_close_clicked()
{
    // 假设您已经在类中定义了一个指向串口对象的指针
    if (serial && serial->isOpen())
    {
        serial->close();
        ui->pushButton_open->setEnabled(true);
        ui->pushButton_close->setEnabled(false);
        ui->pushButton_send->setEnabled(false);
        ui->pushButton_clear->setEnabled(false);
        ui->lineEdit_send->setEnabled(false);

        ui->comboBox_Port->setEnabled(true);
        ui->comboBox_BaudRate->setEnabled(true);
        ui->comboBox_DataBits->setEnabled(true);
        ui->comboBox_StopBits->setEnabled(true);
        ui->comboBox_Parity->setEnabled(true);
        ui->lineEdit_send->clear();
    }
}


void MainWindow::on_pushButton_send_clicked()
{
    if (serial && serial->isOpen())
    {
        QString text = ui->lineEdit_send->text();
        serial->write(text.toLocal8Bit());
        ui->lineEdit_send->clear();
    }
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->plainTextEdit_receive->clear();
    ui->lineEdit_send->clear();
}

void MainWindow::serialPort_readyRead_slot()
{
    if (serial && serial->isOpen())
    {
        QByteArray data = serial->readAll();
        ui->plainTextEdit_receive->appendPlainText(QString(data));
    }
}

