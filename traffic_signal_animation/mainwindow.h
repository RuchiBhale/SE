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
    void dda(int,int,int,int,QRgb);
    void circle(int,int,int,QRgb);
    void Scanline(int[5],int[5],QRgb);
    void translation(int);
   void translationb(int);
    void translate_circle(int);
    void translateb_circle(int);




    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

