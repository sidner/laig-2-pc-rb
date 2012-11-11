#include "Pads.h"
#include <iostream>

using namespace std;
Pads::Pads (Appearance* pads_app)
{

    
    this->pads_app = pads_app;
    
    cube = new myTextureCube();
}

void Pads::draw ()
{
    glPushMatrix ();
    
    pads_app->apply ();
    glTranslatef(0,2,0);
    glScalef(12,0.05,0.5);
    
    cube->draw ();
    
    glPopMatrix();
}