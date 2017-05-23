#include "mapping.h"
#include "score.h"

//#include "sort.h"

bool myCompFunction(const pair<int,double> &a, const pair<int,double> &b){
   return a.second > b.second;  
}

vector< pair<int,double> > arrayToVector(double myArray[], int size){
   vector< pair<int,double> > myVector;
 
   for(int i = 0; i < size; i++){
      if(myArray[i] != 0){
       myVector.push_back(make_pair(i,myArray[i]));      
      }
   }
   return myVector;
}

vector<int> sortDocument(vector< pair<int,double> > myVector){
   vector<int> vReturn;
   sort(myVector.begin(),myVector.end(),myCompFunction);

   vector< pair<int,double> >::iterator it;
   for(it = myVector.begin(); it != myVector.end(); ++it){
       int curr = it->first;
       vReturn.push_back(curr);       
   }
   return vReturn;
}

int main(int argc, char* argv[]){
    if(argc != 4){
        return 1;
    }
    mapping try1;
    try1.create_map(argv[1]);
    //cout << try1.total_num_docs << endl;
    //cout<<"start printing"<<endl;
    /**
    for(map<string,vector<pair<int,int>>>::iterator it=try1.final_map.begin(); it!=try1.final_map.end(); ++it){
        cout << it->first << endl;
        vector< pair<int,int> >::iterator it2;
        for(it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            cout<<it2->first<<" "<<it2->second<<endl;
        }
    }
    **/
    /*
    for(int i = 0; i < try1.total_num_docs; i++){
        cout<<try1.doclength_list[i]<<endl;
    }
    */
    Score s(try1.total_num_docs, try1.doclength_list, &(try1.final_map));
    double *retval = s.scoreQuery(argv[2]);
    vector< pair<int,double> > temp = arrayToVector(retval, try1.total_num_docs);
    vector<int> sorted = sortDocument(temp);
    ofstream outputFile(argv[3]);
    for(int i = 0; i < sorted.size(); i++){
        outputFile<<sorted[i]<<endl;
    }


}

