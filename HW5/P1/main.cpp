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
    fin.open("P1.in");
    fout.open("P1.out");

    //regular expression
    regex sentence_format("([A-z]+)");
    string curr_sentence;
    smatch m;

    //output
    vector<string> words;

    while(getline(fin, curr_sentence)){

        if(!words.empty()){

            //clear output vector each time
            words.clear();

            //separate each output with '\n'
            fout << endl;
        }

        //get words
        auto curr = curr_sentence.cbegin(), last = curr_sentence.cend();
        for(; regex_search(curr, last, m, sentence_format); curr = m.suffix().first)
            words.push_back(m.str());

        //sort & output
        sort(words.begin(), words.end(), greater<string>());
        for(string word : words)
            fout << word << endl;
    }
    return 0;
}
