#include "No.h"

stack<Appearance*> No::pilha;

No::No(string name,string ap, GLfloat m[16], list<string> child_ids)
{
	this->name=name;
	appearanceid=ap;
	for(int i=0;i<16;i++)
	{
		matrix[i] = m[i];
	}
	visited=false;
	this->child_ids=child_ids;
}

void No::draw()
{
	
	glPushMatrix();
	glMultMatrixf(matrix);
	
	if(appearanceid!="inherit")
	{			
		pilha.push(materialAppearance);
	}
	else
	{
		if(!pilha.empty())
			materialAppearance = pilha.top();
	}

	if(!primitives.empty())
	{
		for (list<Primitive*>::iterator it=primitives.begin(); it!=primitives.end(); it++)
		{	
			if(!pilha.empty())
				materialAppearance->apply();
			(*it)->draw();
		}
	}
	
	if(!children.empty())
	{
		for (list<No*>::iterator it=children.begin(); it!=children.end(); it++)
		{
			if(!pilha.empty())
				materialAppearance->apply();
			(*it)->draw();
		}
	}
	if(appearanceid!="inherit")
	{			
		pilha.pop();
	}
	glPopMatrix();
	

}

