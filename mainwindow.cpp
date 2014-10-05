#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , widget(new GLWidget(this))
{
    ui->setupUi(this);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isAltDown() {
    return (QApplication::keyboardModifiers() & Qt::AltModifier) != 0;
}

void MainWindow::keyPressEvent(QKeyEvent *evt)
{
    if (evt->key() == Qt::Key_Escape) {
        close();
    } else if (evt->key() == Qt::Key_Enter && isAltDown()) {
        // TODO: Get go-to fullscreen to work.
        widget->showFullScreen();
    }else {
        QWidget::keyPressEvent(evt);
    }
}
