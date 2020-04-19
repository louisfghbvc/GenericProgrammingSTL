// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <iterator>
#include <random>
#include <time.h>   /* 時間相關函數 */
#include <set>
#include <string.h>
#include <ctype.h>
using namespace std;

using std::ostream;

template<typename T>

ostream& operator<< (ostream& out, const vector<T>& v) {
    for(int i = 0; i < v.size(); ++i) {
        out << v[i];
    }
    return out;
}
char RandomUpperChar()
{
  const string characters = "0123456789";

  static std::default_random_engine generator( time(NULL) );
  static std::uniform_int_distribution<int> random_number(0, 9);

  int rand_num = random_number(generator); // [0, 25] range

  return characters[rand_num];
}
string vector_range(vector<char> A,int a,int b)
{
    string B="";
    for(int i=a;i<b;i++)
    {
        B+=A.at(i);
    }
    return B;
}
int main(int argc, char *argv[])
{
    if(argc!=1)
    {
          vector<char> myset;
          char character;
          int first_input,second_input, tmp, tmp2, tmp3;
          for (int i = 0; i < atoi(argv[1])*atoi(argv[2]); i++)
          {
             character=RandomUpperChar();
             myset.push_back(character);
          }
          vector<char> integer,integer2;
          vector<string> integer3;
          for(int i=3;i<argc;i+=3)
          {
            integer.push_back(atoi(argv[i]));
            integer.push_back(atoi(argv[i+1]));
            integer.push_back(atoi(argv[i+2]));
            cout << myset.at((integer[0]-1)*second_input+integer[1]-1) << " ";
            cout << count(myset.begin(), myset.end(), myset.at((integer[0]-1)*second_input+integer[1]-1)) << " ";
            cout << count(myset.begin(), myset.end(), myset.at((integer[0]-1)*second_input+integer[1]-1)) % integer[2] << endl;
            integer.clear();
            integer2.push_back(myset.at((integer[0]-1)*second_input+integer[1]-1));//record pattern
          }
          int count_number=0;
          cout<<integer2;
          for(int i=0;i<myset.size();i++)
          {
              if(i+integer2.size()<=myset.size())
                integer3.push_back(vector_range(myset,i,i+integer2.size()));
          }
          sort(integer2.begin(),integer2.end());
          do{
                count_number+=count(integer3.begin(),integer3.end(),vector_range(integer2,0,integer2.size()));
          }
          while(next_permutation(integer2.begin(),integer2.end()));
          cout<<" "<<count_number;
    }
    else//no argc default doing
    {
          //char A[]={"86497279124338829853247739010863405293025447146829920344573346706658889267496015380180347051372349465304012511077961308661577303776995189914"};
          vector<char> myset;
          char character;
          int first_input,second_input, tmp, tmp2, tmp3;
          cin>>first_input>>second_input;
          for (int i = 0; i < first_input*second_input; i++)
          {
             character=RandomUpperChar();
             myset.push_back(character);
             //myset.push_back(A[i]);
          }
          vector<char>integer,integer2;
          vector<string> integer3;
          while(cin >> tmp >> tmp2 >> tmp3)
          {
            integer.push_back(tmp);
            integer.push_back(tmp2);
            integer.push_back(tmp3);
            cout << myset.at((integer[0]-1)*second_input+integer[1]-1) << " ";
            cout << count(myset.begin(), myset.end(), myset.at((integer[0]-1)*second_input+integer[1]-1)) << " ";
            cout << count(myset.begin(), myset.end(), myset.at((integer[0]-1)*second_input+integer[1]-1)) % integer[2] << endl;
            integer.clear();
            integer2.push_back(myset.at((integer[0]-1)*second_input+integer[1]-1));//record pattern
          }
          int count_number=0;
          cout<<integer2;
          for(int i=0;i<myset.size();i++)
          {
              if(i+integer2.size()<=myset.size())
                integer3.push_back(vector_range(myset,i,i+integer2.size()));
          }
          sort(integer2.begin(),integer2.end());
          do{
                count_number+=count(integer3.begin(),integer3.end(),vector_range(integer2,0,integer2.size()));
          }
          while(next_permutation(integer2.begin(),integer2.end()));
          cout<<" "<<count_number;
     }
     return 0;
}
//1 1 5 3 17 9 6 20 16
