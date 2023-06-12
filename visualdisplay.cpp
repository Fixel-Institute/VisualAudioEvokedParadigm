#include "visualdisplay.h"
#include "ui_visualdisplay.h"

#include <QtMath>

VisualDisplay::VisualDisplay(QWidget *parent, float flashRate, float contrast) :
    QWidget(parent),
    ui(new Ui::VisualDisplay)
{
    this->timer = new QTimer();
    this->elapsedTimer = new QElapsedTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    this->timer->start(1000/flashRate/2);
    this->elapsedTimer->restart();

    ui->setupUi(this);

    this->ui->gridLayout->setContentsMargins(100,100,100,100);
}

VisualDisplay::~VisualDisplay()
{
    delete ui;
}

void VisualDisplay::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int height = event->size().height();
    int width = event->size().width();
    this->ui->gridLayout->setContentsMargins((width-500)/2,(height-500)/2,(width-500)/2,(height-500)/2);
    this->ui->gridLayout->update();
}

void VisualDisplay::timerTimeout()
{
    int elapseTime = int(this->elapsedTimer->elapsed());
    if (elapseTime < 10000) {
        this->ui->displayLabel->setText(QString("Program Starts in %1...").arg(round(10-elapseTime/1000)));
        this->ui->displayLabel->repaint();
    } else {
        if (onFlash == 0) {
            this->ui->displayLabel->setText("");
            this->ui->displayLabel->setStyleSheet("QLabel { background-color: white }");
        }
        if (onFlash % 2 == 0) {
            this->ui->displayLabel->show();
        } else {
            this->ui->displayLabel->hide();
        }
        onFlash++;
    }
}
