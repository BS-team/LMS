#include "mainwindow.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("C:/Users/albaloo/Documents/ProjectOfTerm2/musicOfProject.mp3"));

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    w.show();
    return a.exec();
}
