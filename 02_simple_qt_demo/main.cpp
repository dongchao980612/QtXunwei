#include "mainwindow.h".h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog dlg;
    MainWindow w;


    //点击主界面的退出按钮，返回登录对话框
    QObject::connect(&w, SIGNAL(MainWindow_exit()), &dlg, SLOT(LoginDialog_login()));

    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
