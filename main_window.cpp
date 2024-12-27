#include "main_window.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , drawCount(5)
{ // 初始抽奖次数
    setFixedSize(800, 600);

    // 背景图片
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap()); // 图片路径留空
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, width(), height());

    // 抽奖按钮
    drawButton = new QPushButton("开始抽奖", this);
    drawButton->setGeometry(width() / 2 - 50, height() - 100, 100, 40);
    connect(drawButton, &QPushButton::clicked, this, &MainWindow::startLottery);

    initializePrizePool();
}

MainWindow::~MainWindow() {}

void MainWindow::initializePrizePool()
{
    // 奖池初始化
    prizePool << "普通奖品1"
              << "普通奖品2"
              << "稀有奖品1"
              << "稀有奖品2"
              << "传奇奖品1";

    // 使用 std::shuffle 打乱奖池
    std::shuffle(prizePool.begin(),
                 prizePool.end(),
                 std::default_random_engine(
                     std::chrono::system_clock::now().time_since_epoch().count()));
}

void MainWindow::startLottery()
{
    if (drawCount <= 0) {
        QMessageBox::warning(this, "提示", "抽奖次数已用完！");
        return;
    }

    drawCount--;

    // 抽奖逻辑
    QString prize = prizePool.takeFirst();
    int rarity = 0; // 判断稀有度
    if (prize.contains("稀有"))
        rarity = 1;
    else if (prize.contains("传奇"))
        rarity = 2;

    // 打开动画窗口
    AnimationWidget *animation = new AnimationWidget(prize, rarity);
    animation->setAttribute(Qt::WA_DeleteOnClose);
    animation->show();
}
