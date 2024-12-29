#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
namespace Ui
{
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_zhuce_clicked();

    void on_pushButton_denglu_clicked();
    void LoginDialog_login();


private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
