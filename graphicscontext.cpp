#include "graphicscontext.h"
#include "glwidget.h"
#include "colorutils.h"

GraphicsContext::GraphicsContext(GLWidget &parent)
    : QObject(&parent)
    , widget(parent)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);

    viewport.reset(new Viewport(*this));
    viewport->setBackgroundColor(ColorUtils::CORNFLOWER_BLUE);
}

void GraphicsContext::setClearColor(const QColor &clearColor)
{
    widget.qglClearColor(clearColor);
}

void GraphicsContext::renderFrame()
{
    viewport->_clear();
}
