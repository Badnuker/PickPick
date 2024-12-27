#ifndef ANIMATION_WIDGET_H
#define ANIMATION_WIDGET_H

#include <QLabel>
#include <QMediaPlayer>
#include <QString>
#include <QVideoWidget>
#include <QWidget>

class AnimationWidget : public QWidget
{
    Q_OBJECT

public:
    AnimationWidget(const QString &prize, int rarity, QWidget *parent = nullptr);
    ~AnimationWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QString prizeName;
    int prizeRarity;
    QLabel *prizeLabel;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    void playAnimation();
};

#endif // ANIMATION_WIDGET_H
