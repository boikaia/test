// ConsoleApplication54.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
	string fam;
	string ima;
	short m;
	short in;
	short fi;
};
bool cmp(student a, student b)
{
	return (a.m + a.in + a.fi) / 3 > (b.m + b.in + b.fi) / 3;
}
int main()
{
	int N;
	cin >> N;
	vector <student> a(N);
	for (int i = 0; i < N; i++)
	{
		int f = 0;
		cin >> a[i].fam;
	cin >> a[i].ima;
		
		cin >> a[i].m >> a[i].in >> a[i].fi;
	}
	stable_sort(a.begin(), a.end(),cmp);
	
	for (auto now : a)
		cout << now.fam<<" " << now.ima << endl;
	return 0;
}