#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QObject>
#include <QColor>
#include <QScopedPointer>
#include "camera.h"

class GraphicsContext;

class Viewport : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Viewport)
public:
    explicit Viewport(GraphicsContext &parent);

    inline GraphicsContext& getContext() {
        return parent;
    }

    inline const GraphicsContext& getContext() const {
        return parent;
    }

    QColor getBackgroundColor() const {
        return backgroundColor;
    }

    void setBackgroundColor(const QColor& color);

    Camera& getCamera() {
        return *camera;
    }
    const Camera& getCamera() const {
        return *camera;
    }

    void _clear();

signals:

public slots:
    void onResize(int width, int height);

private:
    GraphicsContext &parent;
    QColor backgroundColor;
    QScopedPointer<Camera> camera;
};

#endif // VIEWPORT_H
