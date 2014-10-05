#include "scopedmatrixmode.h"
#include <GL/gl.h>

class ScopedMatrixMode::Impl {
public:
    Impl(GLMatrixMode mode) {
        glPushMatrix();
        glMatrixMode(mode);
        glLoadIdentity();
    }

    ~Impl() {
        glPopMatrix();
    }
};

ScopedMatrixMode::ScopedMatrixMode(GLMatrixMode mode)
    : pimpl(new Impl(mode)) {
}
