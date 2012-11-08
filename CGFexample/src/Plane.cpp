#include "Plane.h"

Plane::Plane (int parts)
{
    this->parts = parts;
    
    controlpoints[0][0] = 0.5;
    controlpoints[0][1] = 0.0;
    controlpoints[0][2] = 0.5;
    controlpoints[1][0] = -0.5;
    controlpoints[1][1] = 0.0;
    controlpoints[1][2] = 0.5;
    controlpoints[2][0] = 0.5;
    controlpoints[2][1] = 0.0;
    controlpoints[2][2] = -0.5;
    controlpoints[3][0] = -0.5;
    controlpoints[3][1] = 0.0;
    controlpoints[3][2] = -0.5;
    
    colorpoints[0][0] = 0.2;
    colorpoints[0][1] = 0.2;
    colorpoints[0][2] = 0.2;
    colorpoints[0][3] = 0.0;
    colorpoints[1][0] = 0.2;
    colorpoints[1][1] = 0.2;
    colorpoints[1][2] = 0.2;
    colorpoints[1][3] = 0.0;
    colorpoints[2][0] = 0.2;
    colorpoints[2][1] = 0.2;
    colorpoints[2][2] = 0.2;
    colorpoints[2][3] = 0.0;
    colorpoints[3][0] = 0.2;
    colorpoints[3][1] = 0.2;
    colorpoints[3][2] = 0.2;
    colorpoints[3][3] = 0.0;
    
    textpoints[0][0] = 0.0;
    textpoints[0][1] = 0.0;
    textpoints[1][0] = 0.0;
    textpoints[1][1] = 1.0;
    textpoints[2][0] = 1.0;
    textpoints[2][1] = 0.0;
    textpoints[3][0] = 1.0;
    textpoints[3][1] = 1.0;
}

void Plane::draw ()
{
    glEnable (GL_AUTO_NORMAL);
    glPushMatrix ();

    glMap2f (GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2, 0.0, 1.0, 6, 2, &controlpoints[0][0]);
    glMap2f(GL_MAP2_COLOR_4,  0.0, 1.0, 4, 2,  0.0, 1.0, 8, 2,  &colorpoints[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints[0][0]);
    
    glEnable (GL_MAP2_VERTEX_3);
    glEnable (GL_MAP2_NORMAL);
    glEnable(GL_MAP2_COLOR_4);
    glEnable(GL_MAP2_TEXTURE_COORD_2);

    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, 1);
    glMapGrid2f (parts, 0.0, 1.0, parts, 0.0, 1.0);

    glEvalMesh2 (GL_FILL, 0, parts, 0, parts);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix ();

}