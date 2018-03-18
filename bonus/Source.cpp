#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void main()
{
	string exp;
	cout << "expresie: ";
	cin >> exp;
	string E = infToPost(exp);
	cout << "expresie postfixata:" << endl << "    " << E << endl << endl << endl;
	float rez = EvalExpPostFix(E);
	cout << "rezultat:  " << rez << endl;
}