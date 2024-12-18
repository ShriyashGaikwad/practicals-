// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string,int> statep;
  statep["a"]=123;
  statep["b"]=234;
  statep["c"]=567;
  statep["d"]=890;
  statep["e"]=678;
  statep["f"]=612;
  
  
  string state;
  cout<<"enter the state to search= ";
  cin>>state;

  auto it=statep.find(state);
  
  if(it!=statep.end())
  {
      cout<<"state population of"<<" "<<state<<" "<<"is"<<" "<<it->second;
  }
  else
  {
      cout<<"not find";
  }
    return 0;
}