#include "No.h"

stack<Appearance*> No::pilha;

No::No(string name,string ap, GLfloat m[16], list<string> child_ids,bool isCL)
{
	this->name=name;
	appearanceid=ap;
	for(int i=0;i<16;i++)
	{
		matrix[i] = m[i];
	}
	materialAppearance = NULL;
	visited=false;
	this->child_ids=child_ids;
	isCallList = isCL;
	myCallList = 0;
}

void No::generateCallList()
{
	myCallList = glGenLists(1);
	cout << name << ": " << myCallList << endl;
	glNewList(myCallList,GL_COMPILE);
		glPushMatrix();
		glMultMatrixf(matrix);


		if(appearanceid!="inherit")
		{
			pilha.push(materialAppearance);
		}
		else
		{
			if(!pilha.empty() && appearanceid!="inherit")
				materialAppearance = pilha.top();
		}


		if(!primitives.empty())
		{
			for (list<Primitive*>::iterator it=primitives.begin(); it!=primitives.end(); it++)
			{
				if(!pilha.empty()&& appearanceid!="inherit")
					materialAppearance->apply();
				(*it)->draw();
			}
		}


		if(!children.empty())
		{
			for (list<No*>::iterator it=children.begin(); it!=children.end(); it++)
			{
				if(!pilha.empty() || appearanceid!="inherit" || !isCallList)
				{
					cout << "hello\n";
					materialAppearance->apply();
				}
				(*it)->draw();
			}
		}

		if(appearanceid!="inherit")
		{
			pilha.pop();
		}
		glPopMatrix();

	glEndList();

}


void No::draw()
{
	if(isCallList)
	{
		cout << name << ": " << myCallList << endl;
		glCallList(myCallList);
	}
	else
	{
		cout << name<< ".\n";
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
				{
					cout << materialAppearance->get_t()<<endl;
					materialAppearance->apply();
				}
				(*it)->draw();
			}
		}

		if(!children.empty())
		{
			for (list<No*>::iterator it=children.begin(); it!=children.end(); it++)
			{
				if(!pilha.empty())
				{
					cout << materialAppearance->get_t()<<endl;
					materialAppearance->apply();
				}
				(*it)->draw();
			}
		}
		if(appearanceid!="inherit")
		{
			pilha.pop();
		}
		glPopMatrix();
	}
}
