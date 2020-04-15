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
template<class InputIterator, class T>
  InputIterator find (InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
    cout<<*first<<" ";
    ++first;
  }
  cout<<endl;
  return last;
}

char RandomUpperChar()
{
  const string characters = "0123456789";

  static std::default_random_engine generator( time(NULL) );
  static std::uniform_int_distribution<int> random_number(0, 9);

  int rand_num = random_number(generator); // [0, 25] range

  return characters[rand_num];
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
          vector<int>integer,integer2,integer3;
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
          for (auto it = integer2.begin();it<integer2.end();it++)
              cout << *it-'0';
          integer3.assign(integer2.begin(),integer2.end());
          for(int i=0;i<myset.size();i++)
          {
              auto it = integer3.begin();
              for(int j=0;j<integer3.size();j++)
              {
                if(myset.at(i)==*it)
                {
                  integer3.erase(it);
                  if(integer3.size() == 0 )
                  {
                        count_number++;
                        integer3.assign(integer2.begin(),integer2.end());
                        i=i-integer3.size()+2;
                        integer3.erase(it);
                  }
                  break;
                }
                else
                {
                    if(j==integer3.size()-1)
                    {
                        integer3.assign(integer2.begin(),integer2.end());
                        it = integer3.begin();
                        while(it!=integer3.end()){
                            if(myset.at(i)==*it)
                            {
                              integer3.erase(it);
                              break;
                            }
                            it++;
                        }
                    }
                }
                it++;
              }
          }
          cout<<" "<<count_number<<endl;
    }
    else//no argc default doing
    {
          vector<char> myset;
          char character;
          int first_input,second_input, tmp, tmp2, tmp3;
          cin>>first_input>>second_input;
          for (int i = 0; i < first_input*second_input; i++)
          {
             character=RandomUpperChar();
             myset.push_back(character);
          }
          vector<int>integer,integer2,integer3;
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
          for (auto it = integer2.begin();it<integer2.end();it++)
              cout << *it-'0';
          integer3.assign(integer2.begin(),integer2.end());
          for(int i=0;i<myset.size();i++)
          {
              auto it = integer3.begin();
              for(int j=0;j<integer3.size();j++)
              {
                if(myset.at(i)==*it)
                {
                  integer3.erase(it);
                  if(integer3.size() == 0 )
                  {
                        count_number++;
                        integer3.assign(integer2.begin(),integer2.end());
                        i=i-integer3.size()+2;
                        integer3.erase(it);
                  }
                  break;
                }
                else
                {
                    if(j==integer3.size()-1)
                    {
                        integer3.assign(integer2.begin(),integer2.end());
                        it = integer3.begin();
                        while(it!=integer3.end()){
                            if(myset.at(i)==*it)
                            {
                              integer3.erase(it);
                              break;
                            }
                            it++;
                        }
                    }
                }
                it++;
              }
              //cout<<i<<" "<<integer3.size()<<" "<<myset.at(i)<<endl;
          }
          cout<<" "<<count_number<<endl;
     }
     return 0;
}
//1 1 5 3 17 9 6 20 16
