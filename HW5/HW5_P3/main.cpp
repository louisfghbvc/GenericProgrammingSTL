#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(int argc,char *argv[])
{
    string A;
    smatch m;
    regex e1 ("My phone number is \\+\\(([0-9]{3})\\)\\-(\\d)\\-([0-9]{4})\\-([0-9]{4})\\.");
    regex e2 ("Yours is \\+\\(([0-9]{3})\\)\\-(\\d)\\-([0-9]{4})\\-([0-9]{4}) ");
    regex e3 ("Today is a sunny day and I will call the number \\+\\(([0-9]{3})\\)\\-(\\d)\\-([0-9]{4})\\-([0-9]{4})\\.");
    while(!cin.eof())
    {
        getline(cin,A);
        if(regex_match (A, m,e1))
        {
            A=regex_replace(A, e1,"My phone number is +(XXX)-X-XXXX-$4.");
        }
        else if(regex_match (A, m,e2))
        {
            A=regex_replace(A, e2,"Yours is +(XXX)-X-XXXX-$4.");
        }
        else if(regex_match (A, m,e3))
        {
            A=regex_replace(A, e3,"Today is a sunny day and I will call the number +(XXX)-X-XXXX-$4.");
        }
        cout<<A<<endl;
    }
    return 0;
}
/*
My phone number is +(886)-2-2905-3698.
Yours is +(886)-3-3322-0956
The wrong number is +(123)-5-4412-1233.
Today is a sunny day and I will call the number +(123)-1-1123-3455.
+(886)-3-333-4456
+(88)-2-2905-2698
+(aaa)-b-b123-3388
Goodbye!
*/
