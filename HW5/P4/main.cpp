#include <algorithm>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    //file input/output
    ifstream fin;
    ofstream fout;
    fin.open("P4.in");
    fout.open("P4.out");

    //regular expression
    regex floating_constant_format("((([0-9]*\\.[0-9]+)|([0-9]+\\.))([eE][-+]?[0-9]+)?[fFlL]?)|([0-9]+[eE][-+]?[0-9]+[fFlL]?)");
    string curr_sentence;
    smatch m;

    unsigned curr_pos = 0;

    while(getline(fin, curr_sentence)){

        if(curr_pos != 0){
            //separate each output with '\n'
            fout << endl;
        }

        //match string
        if(regex_match(curr_sentence, floating_constant_format))
            fout << "TRUE" << endl;
        else{
            fout << "FALSE" << endl;

            //search floating constant & output position and floating constant
            auto curr = curr_sentence.cbegin(), last = curr_sentence.cend();
            for(curr_pos = 0; regex_search(curr, last, m, floating_constant_format); curr = m.suffix().first){
                curr_pos += m.position();
                fout << curr_pos << " " << m.str() << endl;
                curr_pos += m.length(0);
            }
        }

        curr_pos = 1;
    }
    return 0;
}
