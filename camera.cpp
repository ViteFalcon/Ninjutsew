#include "camera.h"
#include "viewport.h"
#include "vec3utils.h"
#include "scopedmatrixmode.h"

Camera::Camera(Viewport &parent, const QString &name)
    : QObject(&parent)
    , viewport(parent)
    , name(name)
{
}

void Camera::setPosition(const float x, const float y, const float z)
{
    position.setX(x);
    position.setY(y);
    position.setZ(z);
    isDirty = true;
}

void Camera::setRotation(const float x, const float y, const float z)
{
    rotation.setX(x);
    rotation.setY(y);
    rotation.setZ(z);
    isDirty = true;
}

void Camera::setActive()
{
    ScopedMatrixMode scopedMatrixMode(MATRIXMODE_MODEL_VIEW);
    Vec3Utils::glRotate(rotation);
    Vec3Utils::glTranslate(position);
}
