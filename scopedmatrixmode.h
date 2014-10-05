#ifndef SCOPEDMATRIXMODE_H
#define SCOPEDMATRIXMODE_H

#include "glmatrixmode.h"
#include <QSharedPointer>

class ScopedMatrixMode
{
public:
    explicit ScopedMatrixMode(GLMatrixMode mode);

private:
    class Impl;
    QSharedPointer<ScopedMatrixMode::Impl> pimpl;
};

#endif // SCOPEDMATRIXMODE_H
