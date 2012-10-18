#ifndef NO_H
#define NO_H

#include "CGFobject.h"
#include "Appearance.h"
#include <list>
#include <iostream>
#include "CGFobject.h"
#include "Primitive.h"
#include <stack>

using namespace std;

class No: public CGFobject{	
	public:
		bool visited;
		string name,appearanceid;
		GLfloat matrix[16];
		list<string> child_ids;
		list<No*> children;
		list<Primitive*> primitives;
		Appearance* materialAppearance;
		static stack<Appearance*> pilha;
		No(){};
		
		No(string name,string ap, GLfloat m[16], list<string> child_ids);
		void fill_children(No* child)
		{
			children.push_back(child);
		}
		
		void fill_primitive(Primitive* prim)
		{
			primitives.push_back(prim);
		}
		virtual void draw();
};



#endif
