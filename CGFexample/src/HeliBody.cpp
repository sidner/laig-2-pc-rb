#include "HeliBody.h"
#include <iostream>

using namespace std;
HeliBody::HeliBody (Appearance* heli_app, Appearance* pads_app)
{

    this->heli_app = heli_app;
    this->pads_app = pads_app;
    
    horizontal = new Cylinder (0.5, 0.5, 40, 12, 12);

    vertical1 = new Cylinder (0.5, 0.5, 5, 12, 12);

    vertical2 = new Cylinder (0.5, 0.5, 5, 12, 12);


    GLfloat controlpointsTop[40][3] = {
        {0.2, 0.0, 1.0},
        {0.1, 0.0, 1.0},
        {-0.1, 0.0, 1.0},
        {-0.2, 0.0, 1.0},

        {1.75, 0.0, 0.33},
        {0.75, 3.0, 0.33},
        {-0.75, 3.0, 0.33},
        {-1.75, 0.0, 0.33},

        {0.5, 0.0, -0.33},
        {0.25, 0.5, -0.33},
        {-0.25, 0.5, -0.33},
        {-0.5, 0.0, -0.33},

        {0.5, 0.0, -2.0},
        {0.15, 0.5, -2.0},
        {-0.15, 0.5, -2.0},
        {-0.5, 0.0, -2.0},

        {0.5, 0.0, -2.25},
        {0.15, 0.5, -2.25},
        {-0.15, 0.5, -2.25},
        {-0.5, 0.0, -2.25},

        {0.5, 0.0, -2.5},
        {0.15, 0.5, -2.5},
        {-0.15, 0.5, -2.5},
        {-0.5, 0.0, -2.5},

        {0.5, 0.0, -2.75},
        {0.15, 0.5, -2.75},
        {-0.15, 0.5, -2.75},
        {-0.5, 0.0, -2.75},

        {0.5, 0.0, -3.0},
        {0.15, 0.5, -3.0},
        {-0.15, 0.5, -3.0},
        {-0.5, 0.0, -3.0},

        {0.5, 0.0, -3.25},
        {0.15, 0.5, -3.25},
        {-0.15, 0.5, -3.25},
        {-0.5, 0.0, -3.25},

        {0.5, 1.0, -3.5},
        {0.15, 0.0, -3.5},
        {-0.15, 0.0, -3.5},
        {-0.5, 0.0, -3.5}
    };
    
    GLfloat controlpointsBot[40][3] = {
        {-0.2, 0.0, 1.0},
        {-0.1, 0.0, 1.0},
        {0.1, 0.0, 1.0},
        {0.2, 0.0, 1.0},

        {-1.75, 0.0, 0.33},
        {-0.75, 0.0, 0.33},
        {0.75, 0.0, 0.33},
        {1.75, 0.0, 0.33},

        {-0.5, 0.0, -0.33},
        {-0.25, 0.0, -0.33},
        {0.25, 0.0, -0.33},
        {0.5, 0.0, -0.33},

        {-0.5, 0.0, -2.0},
        {-0.15, 0.0, -2.0},
        {0.15, 0.0, -2.0},
        {0.5, 0.0, -2.0},

        {-0.5, 0.0, -2.25},
        {-0.15, 0.0, -2.25},
        {0.15, 0.0, -2.25},
        {0.5, 0.0, -2.25},

        {-0.5, 0.0, -2.5},
        {-0.15, 0.0, -2.5},
        {0.15, 0.0, -2.5},
        {0.5, 0.0, -2.5},

        {-0.5, 0.0, -2.75},
        {-0.15, 0.0, -2.75},
        {0.15, 0.0, -2.75},
        {0.5, 0.0, -2.75},

        {-0.5, 0.0, -3.0},
        {-0.15, 0.0, -3.0},
        {0.15, 0.0, -3.0},
        {0.5, 0.0, -3.0},

        {-0.5, 0.0, -3.25},
        {-0.15, 0.0 -3.25},
        {0.15, 0.0, -3.25},
        {0.5, 0.0, -3.25},

        {-0.5, 0.0, -3.5},
        {-0.15, 0.0, -3.5},
        {0.15, 0.0, -3.5},
        {0.5, 0.0, -3.5}
    };
    
    
    GLfloat colorpoints[4][3];
    GLfloat textpoints[4][2];

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

    parts[0] = glGenLists (2);
    parts[1] = glGenLists (2);


    //top part
    glNewList (parts[0], GL_COMPILE);

    glEnable (GL_AUTO_NORMAL);
    glPushMatrix ();


    glMap2f (GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 10, &controlpointsTop[0][0]);
    glMap2f (GL_MAP2_COLOR_4, 0.0, 1.0, 4, 2, 0.0, 1.0, 8, 2, &colorpoints[0][0]);
    glMap2f (GL_MAP2_TEXTURE_COORD_2, 0.0, 1.0, 2, 2, 0.0, 1.0, 4, 2, &textpoints[0][0]);

    glEnable (GL_MAP2_VERTEX_3);
    glEnable (GL_MAP2_NORMAL);
    glEnable (GL_MAP2_COLOR_4);
    glEnable (GL_MAP2_TEXTURE_COORD_2);

    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, 1);
    glMapGrid2f (30, 0.0, 1.0, 30, 0.0, 1.0);

    glEvalMesh2 (GL_FILL, 0, 30, 0, 30);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix ();

    glEndList ();


    //bottom part
    glNewList (parts[1], GL_COMPILE);

    glEnable (GL_AUTO_NORMAL);
    glPushMatrix ();


    glMap2f (GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 10, &controlpointsBot[0][0]);
    glMap2f (GL_MAP2_COLOR_4, 0.0, 1.0, 4, 2, 0.0, 1.0, 8, 2, &colorpoints[0][0]);
    glMap2f (GL_MAP2_TEXTURE_COORD_2, 0.0, 1.0, 2, 2, 0.0, 1.0, 4, 2, &textpoints[0][0]);

    glEnable (GL_MAP2_VERTEX_3);
    glEnable (GL_MAP2_NORMAL);
    glEnable (GL_MAP2_COLOR_4);
    glEnable (GL_MAP2_TEXTURE_COORD_2);

    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, 1);
    glMapGrid2f (30, 0.0, 1.0, 30, 0.0, 1.0);

    glEvalMesh2 (GL_FILL, 0, 30, 0, 30);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix ();

    glEndList ();
}
void
HeliBody::draw ()
{
    glPushMatrix ();

    glScalef (2.0, 2.0, 2.0);

    heli_app->apply ();

  glCallList (parts[0]);
  // glCallList (parts[1]);

    glPopMatrix ();

    //FEET
    //left part
    glPushMatrix();
    pads_app->apply();
    
    glPushMatrix ();
    
    glTranslatef (-2.0, 0.0, -0.0);

    //Verticals
    glPushMatrix ();

    glTranslatef (1.0, -0.5, 1.0);
    glScalef (0.1, 0.1, 0.1);

    //V1
    glPushMatrix ();
    glRotatef (-90, 1, 0, 0);
    vertical1->draw ();
    glPopMatrix ();
    //V2
    glPushMatrix ();
    glTranslatef (0, 0, -40);
    glRotatef (-90, 1, 0, 0);
    vertical2->draw ();
    glPopMatrix ();

    glPopMatrix ();

    //Horizontal
    glPushMatrix ();
    glTranslatef (1.0, -0.5, -3.0);
    glScalef (0.1, 0.1, 0.1);
    horizontal->draw ();
    glPopMatrix ();

    glPopMatrix ();


    //right part
    //Verticals
    glPushMatrix ();

    glTranslatef (1.0, -0.5, 1.0);
    glScalef (0.1, 0.1, 0.1);

    //V1
    glPushMatrix ();
    glRotatef (-90, 1, 0, 0);
    vertical1->draw ();
    glPopMatrix ();
    //V2
    glPushMatrix ();
    glTranslatef (0, 0, -40);
    glRotatef (-90, 1, 0, 0);
    vertical2->draw ();
    glPopMatrix ();

    glPopMatrix ();

    //Horizontal
    glPushMatrix ();
    glTranslatef (1.0, -0.5, -3.0);
    glScalef (0.1, 0.1, 0.1);
    horizontal->draw ();
    glPopMatrix ();
    
    glPopMatrix();
}