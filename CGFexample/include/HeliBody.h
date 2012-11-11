#ifndef HELIBODY_H
#define HELIBODY_H

#include "Primitive.h"
#include "Appearance.h"
#include "Cylinder.h"

class HeliBody : public Primitive {
public:
    HeliBody(Appearance* app, Appearance* app2);
    Appearance* heli_app;
    Appearance* pads_app;
    GLuint parts[2];
    Cylinder* horizontal;
    Cylinder* vertical1;
    Cylinder* vertical2;
    void draw();
};

#endif
