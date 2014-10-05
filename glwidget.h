#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QScopedPointer>
#include "graphicscontext.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    inline GraphicsContext& getContext() {
        return *context;
    }
    inline const GraphicsContext& getContext() const {
        return *context;
    }

signals:
    void resized(int width, int height);
private slots:
    virtual void resizeGL(int width, int height);

private:
    static const QColor CORNFLOWER_BLUE;
private:
    virtual void initializeGL();
    virtual void paintGL();

    QScopedPointer<GraphicsContext> context;
};

#endif // GLWIDGET_H
