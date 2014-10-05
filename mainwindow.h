#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsWidget>

#include "glwidget.h"

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
    virtual void keyPressEvent(QKeyEvent *evt);
private:
    Ui::MainWindow *ui;
    GLWidget *widget;
};

#endif // MAINWINDOW_H
