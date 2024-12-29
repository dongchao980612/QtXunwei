#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_tuichu_clicked();
    void on_pushButton_light_clicked();

    void on_pushButton_switch_clicked();

signals:
    void MainWindow_exit();
private:
    Ui::MainWindow *ui;
    bool lightOn = false;
    bool switchOn = false;
};

#endif // MAINWINDOW_H
