#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;

const int mod=1e9;
int main (int argc, char* argv[]){//argv[0] English_name argv[1] group argv[2] length
    int i, j;
    srand( time( NULL ) );
    char alphbet[52];
    alphbet[0]='a';
    for(i=0;i<26;i++)
        alphbet[i+1]=alphbet[i]+1;
    alphbet[26]='A';
    for(i=26;i<52;i++)
        alphbet[i+1]=alphbet[i]+1;
    if(argc!=1)
    {
        int a=atoi(argv[2]),b=atoi(argv[3]),English_name=atoi(argv[1]);
        string name= "N"+to_string(a)+"M"+to_string(b);
        cout<<English_name<<" "<<a<<" "<<b<<endl;
        ofstream out (name+".in");
        for(int k=0;k<a;k++)
        {
            for( j = 0; j < English_name; j++ ){
                out << alphbet[rand()% 52];
            }
            out<<" ";
            for( j = 0; j < b; j++ ){
                out << rand()% mod << " ";
            }
            out << endl;
        }
        out << 0 << " " << 0 << "\n";
        out.close();
    }
    cout<<"end"<<endl;
    return 0;
}






