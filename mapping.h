#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>


using namespace std;

class mapping{
  public:
    mapping();
    void create_map(string inputfile);
    double* doclength_list;
    int total_num_docs;
    map<string,vector<pair<int,int>>> final_map;

};
