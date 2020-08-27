#include "mainwindow.h"
#include<QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;



    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("D:/FinalProjectTerm2/Relax Music 2019 - Nicmusic 01.mp3"));
    //playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    w.show();
    return a.exec();
}
