#ifndef SCORE_H
#define SCORE_H

#include <math.h>
#include <map>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

using std::vector;
using std::map;
class Score{

	public:
		Score();
		Score(int _num_doc, double * doc_length, map<string, vector<pair<int,int>>> *inv_idx);
		~Score();
		double * scoreQuery(string queryFile);
	private:
		double * doc_length;
		map<string, vector<pair<int,int>>> *inv_idx;
		int num_doc;
		double avg_len;
		double b;
		double k1;

};

#endif
