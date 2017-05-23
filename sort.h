#ifndef SORT_H
#define SORT_H
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool myCompFunction(const pair<int,double> &a, const pair<int,double> &b);
vector< pair<int,double> > arrayToVector(double myArray[], int size);
vector<int> sortDocument(vector< pair<int,double> > myVector);

#endif