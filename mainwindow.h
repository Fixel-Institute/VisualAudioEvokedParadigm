
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "visualdisplay.h"

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
    void on_startTaskButton_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    float eventFrequency = 30;
    float eventContrast = 1;

    VisualDisplay *visualDisplayWindow;
};

#endif // MAINWINDOW_H
