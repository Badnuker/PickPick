#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QStringList>
#include "animation_widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startLottery();

private:
    QStringList prizePool;
    int drawCount;
    QPushButton *drawButton;
    QLabel *backgroundLabel;

    void initializePrizePool();
};

#endif // MAIN_WINDOW_H
