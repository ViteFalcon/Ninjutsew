#ifndef VEC3UTILS_H
#define VEC3UTILS_H

#include <GL/gl.h>
#include <QVector3D>

class Vec3Utils
{
public:
    static const QVector3D UNIT_X;
    static const QVector3D UNIT_Y;
    static const QVector3D UNIT_Z;
    static const QVector3D UNIT_SCALE;

    inline static void glTranslate(QVector3D point) {
        glTranslatef(point.x(), point.y(), point.z());
    }

    inline static void glRotate(QVector3D rotation) {
        glRotatef(rotation.x(), 1.0f, 0.0f, 0.0f);
        glRotatef(rotation.y(), 0.0f, 1.0f, 0.0f);
        glRotatef(rotation.z(), 0.0f, 0.0f, 1.0f);
    }

    inline static void glScale(QVector3D scale) {
        glScalef(scale.x(), scale.y(), scale.z());
    }

private:
    Vec3Utils();
    Vec3Utils(const Vec3Utils&);
    Vec3Utils& operator = (const Vec3Utils&);
};

#endif // VEC3UTILS_H
