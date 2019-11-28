#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QTimer>
#include <QLocale>

#include "finder.h"
#include "helpers.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onDirectoryChange(const QString &value);
    void onPatternChange(const QString &value);
    void onBrowseClick();
    void onRestartClick();
    void onStopClick();
    void onPollingTimeout();
    void onStatusAnimationTimeout();

    void setStatus(const QString &status);

private:
    static const int pollingInterval = 200;
    static const int statusAnimationInterval = 200;
    Ui::MainWindow *ui;
    QTimer pollingTimer;
    QTimer statusAnimationTimer;
    Finder bgFinder;
};

#endif // MAINWINDOW_H
