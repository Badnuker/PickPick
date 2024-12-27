#include "animation_widget.h"
#include <QMouseEvent>
#include <QVBoxLayout>

AnimationWidget::AnimationWidget(const QString &prize, int rarity, QWidget *parent)
    : QWidget(parent)
    , prizeName(prize)
    , prizeRarity(rarity)
{
    setFixedSize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 视频播放组件
    videoWidget = new QVideoWidget(this);
    layout->addWidget(videoWidget);

    player = new QMediaPlayer(this);
    player->setVideoOutput(videoWidget);

    // 奖品展示
    prizeLabel = new QLabel(this);
    prizeLabel->setAlignment(Qt::AlignCenter);
    prizeLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    prizeLabel->hide();
    layout->addWidget(prizeLabel);

    playAnimation();
}

AnimationWidget::~AnimationWidget() {}

void AnimationWidget::playAnimation()
{
    QString videoPath;

    // 根据稀有度选择动画视频路径
    switch (prizeRarity) {
    case 0:
        videoPath = ""; // 普通奖品动画路径
        break;
    case 1:
        videoPath = ""; // 稀有奖品动画路径
        break;
    case 2:
        videoPath = ""; // 传奇奖品动画路径
        break;
    }

    if (!videoPath.isEmpty()) {
        player->setSource(QUrl::fromLocalFile(videoPath));
        player->play();
        connect(player,
                &QMediaPlayer::mediaStatusChanged,
                this,
                [this](QMediaPlayer::MediaStatus status) {
                    if (status == QMediaPlayer::EndOfMedia) {
                        prizeLabel->setText("获得奖品：" + prizeName);
                        prizeLabel->show();
                    }
                });
    } else {
        prizeLabel->setText("获得奖品：" + prizeName);
        prizeLabel->show();
    }
}

void AnimationWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    close(); // 点击任意位置关闭窗口
}
