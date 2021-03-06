#include "myTextureCube.h"

void myTextureCube::draw() { //Desenha um quadrado de um lado de aresta, mete-o na posição x=y=-0,5 para centrar na origem, z=0.5 para criar um dos lados e depois cria quadrados iguais, mas rodando-os em torno do eixo dos yy para criar os restantes lados e em torno dos xx para criar os topos.
	
	glPushMatrix();
		glNormal3f(0,0,1);
		glTranslatef(-0.5,-0.5,0.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex2d(0,0);
			glTexCoord2f(1,0);
			glVertex2d(1,0);
			glTexCoord2f(1,1);
			glVertex2d(1,1);
			glTexCoord2f(0,1);
			glVertex2d(0,1);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180,0,1,0);
	glNormal3f(0,0,1);
	glTranslatef(-0.5,-0.5,0.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex2d(0,0);
			glTexCoord2f(1,0);
			glVertex2d(1,0);
			glTexCoord2f(1,1);
			glVertex2d(1,1);
			glTexCoord2f(0,1);
			glVertex2d(0,1);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glNormal3f(0,0,1);
	glTranslatef(-0.5,-0.5,0.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex2d(0,0);
			glTexCoord2f(1,0);
			glVertex2d(1,0);
			glTexCoord2f(1,1);
			glVertex2d(1,1);
			glTexCoord2f(0,1);
			glVertex2d(0,1);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(-90,0,1,0);
	glNormal3f(0,0,1);
	glTranslatef(-0.5,-0.5,0.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex2d(0,0);
			glTexCoord2f(1,0);
			glVertex2d(1,0);
			glTexCoord2f(1,1);
			glVertex2d(1,1);
			glTexCoord2f(0,1);
			glVertex2d(0,1);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,1,0,0);
	glNormal3f(0,0,1);
	glTranslatef(-0.5,-0.5,0.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex2d(0,0);
			glTexCoord2f(1,0);
			glVertex2d(1,0);
			glTexCoord2f(1,1);
			glVertex2d(1,1);
			glTexCoord2f(0,1);
			glVertex2d(0,1);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(-90,1,0,0);
	glNormal3f(0,0,1);
	glTranslatef(-0.5,-0.5,0.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex2d(0,0);
			glTexCoord2f(1,0);
			glVertex2d(1,0);
			glTexCoord2f(1,1);
			glVertex2d(1,1);
			glTexCoord2f(0,1);
			glVertex2d(0,1);
		glEnd();
	glPopMatrix();
}
