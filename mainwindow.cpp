
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->visualDisplayWindow = NULL;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startTaskButton_clicked()
{
    this->visualDisplayWindow = new VisualDisplay(nullptr, this->eventFrequency, this->eventContrast);
    this->visualDisplayWindow->show();
    this->hide();
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    this->eventFrequency = arg1;
}

