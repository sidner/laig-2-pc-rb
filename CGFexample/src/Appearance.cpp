#include "Appearance.h"
#include "CGFapplication.h"


#define CG_GLMAT_COLOR 0
#define CG_GLMAT_MATERIAL 1
#define CG_GLMAT_TEXTURE 2

#include "imagetools.h"

#include <iostream>


Appearance::Appearance()
{
	try {
		color[0] = 0.5;
		color[1] = 0.5;
		color[2] = 0.5;
		color[3] = 1;

		materialType = CG_GLMAT_COLOR;

		texture=NULL;
	}
	catch(std::exception&) {
		throw GLexception("Appearance::constructor failed");
	}

}

Appearance::Appearance(float* e, float* a, float* d, float* sp, float sh) 
{
	try {
		emissive[0] = e[0];
		emissive[1] = e[1];
		emissive[2] = e[2];
		emissive[3] = e[3];
		
		ambient[0] = a[0];
		ambient[1] = a[1];
		ambient[2] = a[2];
		ambient[3] = a[3];

		diffuse[0] = d[0];
		diffuse[1] = d[1];
		diffuse[2] = d[2];
		diffuse[3] = d[3];
		
		specular[0] = sp[0];
		specular[1] = sp[1];
		specular[2] = sp[2];
		specular[3] = sp[3];

		shininess = sh;

		materialType = CG_GLMAT_MATERIAL;

		texture=NULL;
	}
	catch(std::exception&) {
		throw GLexception("Appearance::constructor failed");
	}
}

Appearance::Appearance(float* a, float* d, float* sp, float sh) 
{
	try {
		ambient[0] = a[0];
		ambient[1] = a[1];
		ambient[2] = a[2];
		ambient[3] = a[3];

		diffuse[0] = d[0];
		diffuse[1] = d[1];
		diffuse[2] = d[2];
		diffuse[3] = d[3];
		
		specular[0] = sp[0];
		specular[1] = sp[1];
		specular[2] = sp[2];
		specular[3] = sp[3];

		shininess = sh;

		materialType = CG_GLMAT_MATERIAL;

		texture=NULL;
	}
	catch(std::exception&) {
		throw GLexception("Appearance::constructor failed");
	}
}

Appearance::Appearance(float* c) 
{
	try {
		color[0] = c[0];
		color[1] = c[1];
		color[2] = c[2];
		color[3] = c[3];

		materialType = CG_GLMAT_COLOR;

		texture=NULL;
	}
	catch(std::exception&) {
		throw GLexception("Appearance::constructor failed");
	}
}

Appearance::~Appearance() 
{

}

void Appearance::apply() 
{

	if(materialType==CG_GLMAT_MATERIAL) {
		glDisable(GL_COLOR_MATERIAL);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_SPECULAR,  specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,   diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT,   ambient);
		glMaterialfv(GL_FRONT, GL_EMISSION, emissive);
	}
	else if(materialType==CG_GLMAT_COLOR) {
		glEnable(GL_COLOR_MATERIAL);
		glColor4fv(color);
	}

	if (texture!=NULL)
	{
		glEnable(GL_TEXTURE_2D);
		texture->apply();	       
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sWrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, tWrap);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glScalef(length_s,length_t,1);
		glMatrixMode(GL_MODELVIEW);
	}
	else
		glDisable(GL_TEXTURE_2D);	       
}

void Appearance::setAmbient(float* li) 
{
	ambient [0] = li[0];
	ambient [1] = li[1];
	ambient [2] = li[2];
	ambient [3] = li[3];
}

void Appearance::setDiffuse(float* li) 
{
	diffuse [0] = li[0];
	diffuse [1] = li[1];
	diffuse [2] = li[2];
	diffuse [3] = li[3];
}

void Appearance::setSpecular(float* li) 
{
	specular [0] = li[0];
	specular [1] = li[1];
	specular [2] = li[2];
	specular [3] = li[3];
}

void Appearance::setShininess(float shi) 
{
	shininess = shi;
}

void Appearance::setTexture(string t) 
{
	texture=new CGFtexture(t);
}

void Appearance::setTexture(CGFtexture *tp) 
{
	texture=tp;
}

void Appearance::setTextureWrap(int s, int t)
{
		sWrap=s;
		tWrap=t;
}

Appearance::Appearance(string tex, int s, int t)
{
	try {
		Appearance();

		setTexture(tex);

		setTextureWrap(s,t);
	}
	catch (GLexception& ex) {
		throw ex;
	}
	catch (std::exception&) {
		throw GLexception("Appearence::constructor for texture failed");
	}
}

void Appearance::set_lengths(float s, float t)
{
	length_s = 1.0/s;
	length_t = 1.0/t;
}
