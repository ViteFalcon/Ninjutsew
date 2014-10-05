#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QMatrix4x4>
#include <QVector3D>
#include <QString>
#include <GL/gl.h>

class Viewport;

class Camera : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Camera)
public:
    Camera(Viewport &parent, const QString& name);

    Viewport& getViewport() {
        return viewport;
    }

    const Viewport& getViewport() const {
        return viewport;
    }

    QString getName() const {
        return name;
    }

    QVector3D getPosition() {
        return position;
    }

    QVector3D getPosition() const {
        return position;
    }

    inline void setPosition(const QVector3D& position) {
        setPosition(position.x(), position.y(), position.z());
    }
    void setPosition(const float x, const float y, const float z);

    QVector3D getRotation() const {
        return rotation;
    }
    inline void setRotation(const QVector3D& rotation) {
        setRotation(rotation.x(), rotation.y(), rotation.z());
    }
    void setRotation(const float x, const float y, const float z);

    void setActive();

signals:

public slots:

private:
    Viewport& viewport;
    const QString name;
    bool isDirty;
    QMatrix4x4 cameraMatrix;
    QVector3D position;
    QVector3D rotation;
};

#endif // CAMERA_H
