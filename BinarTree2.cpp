#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>



using namespace std;

struct Tree
{
	Tree *l;
	Tree *r;
	int x;
};
queue <int> SKLAD;
int a_gl, level=0;
stack <Tree *> dno;
int list = 0;
Tree *tree(nullptr);

void del(int);

//void del(Tree **, int);
void show(Tree**, int);

void add(Tree** t, int n)
{
	    
	if (!(*t)) //вставка элемента
	{
		(*t) = new Tree;
		(*t)->x = n;
		(*t)->l = (*t)->r = nullptr;
		
		if (level == 0) a_gl = n;
		level++;
		
		Tree *p1, *p2;
		p1 = p2  = nullptr;

		if (!dno.empty())
		{
			p1 = dno.top();
			dno.pop();
		}
		if (dno.empty()) return;
		p2 = dno.top();
		dno.pop();
		
		while (!dno.empty()) dno.pop();

		if (((*t)->x >= p1->x) && (p1->x >= p2->x))
			if (p1->l == nullptr && p2->l == nullptr)
			{				
				del(p2->x);
				add(&tree, p2->x);
				if (level == 3) a_gl = p1->x;
				return;
			}

		if (((*t)->x <= p1->x) && (p1->x <= p2->x))
			if (p1->r == nullptr && p2->r == nullptr)
			{
				
				del(p2->x);
				add(&tree, p2->x);
				if (level == 3) a_gl = p1->x;
				return;
			}
		return;
	        
	}
	if (n <= (*t)->x)
	{
		dno.push(*t);
		add(&(*t)->l, n);
	}
	else
	{
		dno.push(*t);
		add(&(*t)->r, n);
	}
}




void show(Tree** t, int lev)
{
	if (!(*t))
		return;
	for (int i(0); i < lev; i++)
		cout << "   ";
	cout << (*t)->x << endl;
	show(&(*t)->l, lev - 1);
	show(&(*t)->r, lev + 1);
}


//подсчет листьев
int kol_list(Tree* t)
{	
	if (!t)	return list;
	if ((t->l == nullptr) && (t->r == nullptr))	 list++;
		
	kol_list(t->l);
	kol_list(t->r);
	
}



void fun(Tree **t)
{
	if (*t == nullptr) return;
	else 
	{
		SKLAD.push((*t)->x);
		level--;
	//cout << SKLAD.back()<<" ";
		fun(&(*t)->l);
		fun(&(*t)->r);
	}
}

void del(int a)
{
	Tree **t;
	t = &tree;
	if (t == nullptr) { cout << "empty tree" << endl; return; }
	Tree *p;
	int n = 0;
	p = (*t);
	
	while ((p->x != a) && (n <= level))  //поиск адреса удаляемого числа
	{ 
		if (p == nullptr) { n = level + 1; break; }
		if (p->x > a)
		{  n++;
			if (p->l != nullptr)
				p = p->l;
		}
		if (p->x < a)
		{	n++;
			if (p->r != nullptr)
				p = p->r;
		}
	}
	if (n > level)
	{ cout << "No found" << endl;
	  return;
    }
	fun(&p->l);
	fun(&p->r);
	
	Tree *w;
	w = (*t);
	
	if (p->x != a_gl)
	{
		while (w->l != p && w->r != p) //поиск элемента, который ссылается на удаляемый
		{
			if (w->x > p->x)  w = w->l;
			else w = w->r;
		}
		if (p->x < w->x)
			w->l = nullptr;
		else w->r = nullptr;
	}
	else (*t) = nullptr;

	while (!SKLAD.empty())
	{
		add(&(*t), SKLAD.front());
		SKLAD.pop();
	}
	level--;
}



int main()
{
	
	//Tree *tree(nullptr);
	int i;
	cout << "Enter for ADDING:(DEL: -1; NUMBER of leaves -2;  EXIT: -3)";
	cin >> i;

	while (i != -3)
	{ if((i!=-1)&&(i!=-2))
	  {
		add(&tree, i);
		show(&tree, level);
		cout << endl;
	  }
	  if (i==-1)
	  {
		cout << "Enter for DELETING:";
		cin >> i;
		del(i);
		show(&tree, level);
		cout << endl;
	   }
	  if (i == -2)
	  {
		  cout << "Enter root of the subtree:";
		  cin >> i;
		  list = 0;
		  //poisk adres in main
		  Tree **t;
		  t = &tree;
		  if (t != nullptr)
		  {
			 Tree *p;
		     int n = 0;
		     p = (*t);

		     while ((p->x != i) && (n <= level))  //поиск адреса числа
		     {
			   if (p == nullptr) { n = level + 1; break; }
			   if (p->x > i)
			   {
				  n++;
				  if (p->l != nullptr)
					  p = p->l;
			   }
			  if (p->x < i)
			  {
				  n++;
				  if (p->r != nullptr)
					  p = p->r;
			  }
		  }
		  if (n > level)
			  cout << "No found" << endl;
		  else 
		  {
			  if ((p->l == nullptr) && (p->r == nullptr))
				  cout << "number of leaves=0" << endl;
			  else
			   cout << "number of leaves=" << kol_list(p) << endl;
		  }
	  }
		  else{ cout << "empty tree" << endl; }


	  }
	   cout << "Enter for ADDING:(DEL: -1;NUMBER of leaves -2;  EXIT: -3)";
	   cin >> i;
	}
		
	return 0;
}
