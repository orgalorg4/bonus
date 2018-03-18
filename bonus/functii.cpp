#include "Header.h"
#include <string>
using namespace std;

void push(Element *&cap, int val)
{
	Element *p;
	p = new Element;
	p->data = val;
	p->leg = cap;
	cap = p;
}
void push(Numar *&cap, float val)
{
	Numar *p;
	p = new Numar;
	p->data = val;
	p->leg = cap;
	cap = p;
}
char pop(Element *&cap)
{
	Element *p;
	char c;
	if (cap)
	{
		c = cap->data;
		p = cap;
		cap = cap->leg;
		delete p;
	}
	return c;
}
float pop(Numar *&cap)
{
	Numar *p;
	float n;
	if (cap)
	{
		n = cap->data;
		p = cap;
		cap = cap->leg;
		delete p;
	}
	return n;
}
char peek(Element *&cap)
{
	return cap->data;
}

string infToPost(string exp)
{
	Element *s = 0;
	string EP;
	for (int i = 0;i < size(exp);i++)
	{
		if (isdigit(exp[i]))
		{
			EP += exp[i];
		}
		else
		{
			if ((exp[i] == '+' || exp[i] == '-') && s)
			{
				char c = peek(s);
				while ((c == '*' || c == '/') && s)
				{
					EP += pop(s);
					c = peek(s);
				}
			}
			if (exp[i] == ')')
			{
				char c = peek(s);
				while (c != '(' && s)
				{
					EP += pop(s);
					c = peek(s);
				}
				pop(s);
			}
			else push(s, exp[i]);
		}
	}
	while (s)EP += pop(s);
	return EP;
}

float EvalExpPostFix(string exp)
{
	Numar *s = 0;
	int i = 0;
	while (i < size(exp))
	{
		if (isdigit(exp[i]))
			push(s, exp[i] - 48);
		else
		{
			float v1 = pop(s);
			float v2 = pop(s);
			float r;
			switch (exp[i])
			{
			case '+':
				r = v2 + v1;
				break;
			case '-':
				r = v2 - v1;
				break;
			case '*':
				r = v2 * v1;
				break;
			case '/':
				r = v2 / v1;
				break;
			}
			push(s, r);
		}
		i++;
	}

	return pop(s);
}
