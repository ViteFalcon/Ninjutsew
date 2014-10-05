#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

#include <QObject>
#include <QScopedPointer>
#include "viewport.h"

class GLWidget;

class GraphicsContext : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(GraphicsContext)
public:
    explicit GraphicsContext(GLWidget &parent);

    void setClearColor(const QColor& clearColor);

    inline Viewport& getViewport() {
        return *viewport;
    }
    inline const Viewport& getViewport() const {
        return *viewport;
    }

    void renderFrame();

signals:

public slots:
private:
    GLWidget& widget;
    QScopedPointer<Viewport> viewport;
};

#endif // GRAPHICSCONTEXT_H
