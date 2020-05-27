#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(int argc,char *argv[])
{
    int B;
    string A;
    smatch m;
    regex e ("(\\d\\d\\d\\d)-(\\d\\d\\d\\d)-(\\d\\d\\d\\d)-(\\d\\d\\d\\d)");
    while(cin>>A)
    {
        B=0;
        if(regex_match (A, m, e))
        {
             for (smatch::iterator it = m.begin(); it!=m.end(); it++)
                 if(it!=m.begin())
                    B+=stoi(*it);
            cout<<"TRUE "<<B<<endl;
        }
        else
            cout<<"FALSE"<<endl;
        cout<<endl;
    }
    return 0;
}
