#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
bool comp (string a,string b)
{string lower_a=a;
    string lower_b=b;
     transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
     transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
    return (lower_a<lower_b); }

void Test_comp(){
assert(comp("ABC","abc")==false);
assert(comp("ABCa","abce")==true);
assert(comp("ABCa","0bce")==false);
cout<<"test_comp,OK"<<endl;
}

int main()
{
    Test_comp();


    vector<string> a;
    string b;

    fstream start("start.txt", ios::in);
    fstream result("result.txt", ios::app | ios::out);

    string delete_word;
    cout<<"Enter delete_word "<<endl;
    cin>>delete_word;

    while(getline(start,b)){
   for(size_t found=b.find(delete_word);found!=string::npos;){
                    b.erase(b.find(delete_word),delete_word.size());
                    found=b.find(delete_word);
                                                             }

   a.push_back(b);
                            }

    sort(a.begin(),a.end(),comp);

   for(vector<string>::iterator iter=a.begin();iter!=a.end();iter++)
       result<<*iter<<endl;

  start.close();
  result.close();

    return 0;
}
