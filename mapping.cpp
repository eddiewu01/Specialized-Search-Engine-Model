#include "mapping.h"

mapping::mapping(){
    doclength_list = NULL;
    total_num_docs = 0;

}

void mapping::create_map(string inputfile){
    string line;
    ifstream myfile(inputfile);
    stringstream iss;
    string value;
    map<string,vector<pair<int,int>>> return_map;
    int i = 0;
    vector<int> lengths;
    if(myfile.is_open()){
        //cout << "file open" << endl;
        getline(myfile,line);
        
        iss << line;
        while(getline(iss,value,' ')){
            int number = atoi(value.c_str());
            //doclength_list[i] = number;
            lengths.push_back(number);
            i++;
        }
        while(getline(myfile,line)) {
            //cout << "start making map" << endl;
            string hold1;
            int hold2;
            int hold3;
            stringstream myString(line);
            vector<string> temp;
            while (getline(myString, value, ' ')) {
              temp.push_back(value);
            }
            vector<string>::iterator it = temp.begin();
            hold1 = *it;
            it = it + 1;
            hold2 = atoi((*it).c_str());
            it = it + 1;
            hold3 = atoi((*it).c_str());

            if (return_map.find(hold1)==return_map.end()) {
                vector<pair<int,int>> temp;
                temp.push_back(make_pair(hold2,hold3));
                return_map.insert(make_pair(hold1, temp));
            }
            else{
                return_map[hold1].push_back(make_pair(hold2,hold3));
            }
        }

    }
    doclength_list = new double[lengths.size()];
    for(int j = 0; j < lengths.size(); j++){
        doclength_list[j] = lengths[j];
    }
    final_map = return_map;
    total_num_docs = i;
}

