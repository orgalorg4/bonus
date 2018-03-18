#pragma once
#include <string>
using namespace std;

struct Element
{
	char data;
	Element *leg;
};
struct Numar
{
	float data;
	Numar *leg;
};

void push(Element *&cap, int val);
char pop(Element *&cap);
char peek(Element *&cap);

string infToPost(string exp);
float EvalExpPostFix(string exp);