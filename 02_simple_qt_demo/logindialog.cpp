#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->lineEdit_mima->setEchoMode(QLineEdit::Password);

    ui->pushButton_denglu->setShortcut(Qt::Key_Return);// 添加回车登录功能
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_zhuce_clicked()
{

}


void LoginDialog::on_pushButton_denglu_clicked()
{
    //判断用户名和密码是否正确
    if (ui->lineEdit_yonghuming->text().trimmed() == tr("admin") &&
            ui->lineEdit_mima->text().trimmed() == tr("root"))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("用户名或者密码错误"), QMessageBox::Yes);
    }
    ui->lineEdit_yonghuming->clear();
    ui->lineEdit_mima->clear();

    ui->lineEdit_yonghuming->setFocus();

}

void LoginDialog::LoginDialog_login()																 //接收到try_exit()信号后执行的响应函数
{
    ui->lineEdit_yonghuming->clear();
    ui->lineEdit_mima->clear();
    this->show();
}


