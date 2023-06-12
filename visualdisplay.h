#ifndef VISUALDISPLAY_H
#define VISUALDISPLAY_H

#include <QResizeEvent>
#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>

namespace Ui {
class VisualDisplay;
}

class VisualDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit VisualDisplay(QWidget *parent = nullptr, float flashRate = 10, float contrast = 1);
    ~VisualDisplay();

public slots:
    void timerTimeout();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::VisualDisplay *ui;

    float startTime = 0;
    QTimer *timer;
    QElapsedTimer *elapsedTimer;

    int onFlash = false;
};

#endif // VISUALDISPLAY_H
