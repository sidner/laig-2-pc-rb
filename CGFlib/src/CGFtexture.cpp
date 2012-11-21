#include "CGFtexture.h"

#include "CGFapplication.h"
#include "imagetools.h"

#include <iostream>

unsigned int CGFtexture::counter = 0;

CGFtexture::CGFtexture()
{
	texID=-1;
}

CGFtexture::CGFtexture(string t)
{
	loadTexture(t);
}


CGFtexture::~CGFtexture() 
{

}

void CGFtexture::apply() 
{
	if (texID!=-1)
		glBindTexture(GL_TEXTURE_2D, texID);
}


void CGFtexture::myGenTexture (unsigned int * ID)
{
    counter = counter + 1;
    
    (*ID) = counter;
    
}

void CGFtexture::loadTexture(string t) 
{
	texName=t;
    printf("Loading %s texture before giving ID with ID=%d\n", t.c_str(),texID);
    
	//if (texID==-1 || texID == 0)
   // {
        myGenTexture (&texID);
   // }
    
	unsigned char *data = loadRGBImage(texName.c_str(), &texWidth, &texHeight);
	if (data)
	{
        printf("Loading %s as texture ID %d and counter is %d\n", t.c_str (), texID, counter);
		glPixelStorei(GL_UNPACK_ROW_LENGTH, texWidth);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		glBindTexture(GL_TEXTURE_2D, texID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		free(data);	
	}
	else
		throw GLexception("CGFtexture::loadTexture failed");
}

