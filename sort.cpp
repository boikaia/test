// ConsoleApplication53.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector <long> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	reverse (a.begin(), a.end());
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
    return 0;
}

