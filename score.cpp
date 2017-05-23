#include "score.h"

using namespace std;

Score::Score()
{
	doc_length = NULL;
	inv_idx = NULL;
	avg_len = 0.0;
	b = 0.75;
	k1 = 1.6;
}

Score::Score(int _num_doc, double * _doc_length, map<string, vector<pair<int,int>>> *_inv_idx)
{
	doc_length = _doc_length;
	inv_idx = _inv_idx;
	double sum = 0.0;
	num_doc = _num_doc;
	for(int i = 0; i < _num_doc; i++){
		sum += doc_length[i];
	}
	avg_len = sum/num_doc;
	b = 0.75;
	k1 = 1.6;	
}

Score::~Score()
{
	delete [] doc_length;
	doc_length = NULL;
}

double * Score::scoreQuery(string queryFile)
{
	ifstream queries(queryFile);

	double * retval = new double[num_doc];
	for(int i = 0; i < num_doc; i++){
		retval[i] = 0;
	}
	
	string term;

	while ( ! queries.eof() ){
	    ifstream::int_type x = queries.get();
	    //cout<<x<<endl;

	    while ( x != ' ' && x != std::ifstream::traits_type::eof() && x != 10){
	        term += static_cast<char>(x);
	        x = queries.get();
	        cout<<x<<endl;
	    }
	    //cout<<"term: "<<term<<endl;
	    //cout<<term.length()<<endl;
	    if(inv_idx->find(term) != inv_idx->end()){
	    	vector<pair<int,int>> plist = (*inv_idx)[term];
	    	//cout<<plist.size()<<endl;
			for(auto it = plist.begin(); it != plist.end(); it++){
				pair<int, int> id_count = *it;
				//cout<<"in: ";
				//cout<<id_count.first<<","<<id_count.second<<endl;
				double idf = log((num_doc - plist.size() + 0.5)/(plist.size() + 0.5));
				//cout<<num_doc<<","<<plist.size()<<","<<idf<<endl;
				retval[id_count.first] += idf * id_count.second * (k1+1)/(id_count.second + (k1*(1-b+(b*doc_length[id_count.first]/avg_len))));

			}

	    }
	    
	    
	    term.clear();
	}

	return retval;
	
}
