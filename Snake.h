#pragma once

#include "ui_Snake.h"

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>

#include <vector>
#include <string>

namespace Ui {
    class Snake;
}

class Snake : public QMainWindow {

    Q_OBJECT

public:
    explicit Snake(QWidget* parent = Q_NULLPTR);

private:
    Ui::SnakeClass ui;

    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
    void keyPressEvent(QKeyEvent*);

    static const int kWidth = 1080;
    static const int kHeight = 720;
    static const int kSizeDot = 10;
    static const int kAllDots = kWidth * kHeight;
    static const int kRandPos = 20;
    static const int kDelay = 150;

   // QWidget* centralWidget;

    QImage dot;
    QImage head;
    QImage fruit;
    //const QString& imgPath = "C:\VisualStudio\Qt\Snake\img";

    int timerId;
    int snakeDots;
    int fruitX;
    int fruitY;

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    std::vector<int> x;
    std::vector<int> y;

    void loadImage();
    void initGame();
    void locateFruit();
    void checkFruit();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter&);

    //void paintObject();
};