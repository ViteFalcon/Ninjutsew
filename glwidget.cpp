#include "glwidget.h"
#include <QColor>
#include "viewport.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(1600, 900);
}

void GLWidget::initializeGL()
{
    context.reset(new GraphicsContext(*this));
}

void GLWidget::resizeGL(int width, int height)
{
    context->getViewport().onResize(width, height);
}

void GLWidget::paintGL()
{
    context->renderFrame();
}
