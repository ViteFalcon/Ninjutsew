#include "viewport.h"
#include "glwidget.h"
#include "scopedmatrixmode.h"
#include <qopengl.h>

Viewport::Viewport(GraphicsContext &parent)
    : QObject(&parent)
    , parent(parent)
    , camera(new Camera(*this, "default"))
{
}

void Viewport::setBackgroundColor(const QColor &color)
{
    backgroundColor = color;
    parent.setClearColor(color);
}

void Viewport::_clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->setActive();
}

void Viewport::onResize(int width, int height)
{
    // FIXME: Why's this getting called 3 times?
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    ScopedMatrixMode matrixMode(MATRIXMODE_PROJECTION);
    glFrustum(-1.0, +1.0, -1.0, 1.0, 5.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -40.0);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
}
