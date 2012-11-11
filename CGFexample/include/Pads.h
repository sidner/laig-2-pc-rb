#ifndef PADS_H
#define PADS_H

#include "Primitive.h"
#include "Appearance.h"
#include "myTextureCube.h"

class Pads : public Primitive {
public:
    Pads(Appearance* pads_app);
    Appearance* pads_app;
    myTextureCube* cube;
    void draw();
};

#endif
