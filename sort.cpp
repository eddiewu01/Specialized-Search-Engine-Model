#include "sort.h"

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

/*int main(){
   double myArray[5];
   myArray[0] = 10.9;
   myArray[1] = 7.9;
   myArray[2] = 8.1;
   myArray[3] = 1.5;
   myArray[4] = 3.0;
   int size = sizeof(myArray)/sizeof(myArray[0]);
   cout<<size<<endl;
   vector< pair<int,double> > h = arrayToVector(myArray,size);
   vector< pair<int,double> >::iterator it1;
   for(it1 = h.begin(); it1 != h.end(); ++it1){
       cout<<it1->second<<endl;
   }
   vector<int> r = sortDocument(h);
   vector<int>::iterator it;
   for(it = r.begin(); it != r.end(); ++it){
       cout<<*it;
   }
   return 0;
}*/
