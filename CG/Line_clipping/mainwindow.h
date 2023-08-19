#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dda(int,int,int,int,QRgb);
    void lineclip(int,int,int,int);
    void on_pushButton_2_clicked();
    int Code_compute(float,float);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
