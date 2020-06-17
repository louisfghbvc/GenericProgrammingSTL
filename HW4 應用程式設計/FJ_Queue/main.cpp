#include <bits/stdc++.h>
typedef long long LL; // short cut for long long
using namespace std;

int main()
{
    string str;
    set<string> st; // set for name
    unordered_map<LL, string> bagToName;
    vector<LL> arr;
    vector<LL> reverseLis; // just length
    vector<int> ind; // true index of lis

    while(getline(cin, str)){
        if(str == "0 0") break;

        stringstream ss(str); // split string
        string name;
        ss >> name;
        if(st.count(name)) continue; // already exist
        st.insert(name);

        int value;
        vector<int> bag; // bag for value
        while(ss >> value){
            bag.push_back(value);
        }

        LL total = accumulate(bag.begin(), bag.end(), 0, [](LL a, LL b){
                                return a<b ? a+b : a-b;
                              });
        arr.push_back(total);
        if(!bagToName.count(total))
            bagToName[total] = name; // trace name
    }

    if(arr.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    ind.resize((int)arr.size(), 0);

    reverseLis.push_back(arr.back());
    for(int i = arr.size()-2; i >= 0; --i){
        if(reverseLis.back() < arr[i]){
            reverseLis.push_back(arr[i]);
            ind[i] = reverseLis.size()-1;
        }
        else{
            auto it = lower_bound(reverseLis.begin(), reverseLis.end(), arr[i]);
            ind[i] = it-reverseLis.begin();
            *it = arr[i];
        }
    }

    int ldsLen = reverseLis.size();
    cout << ldsLen << endl; // new menu size
    bool first = true;
    for(int i = 0; i < (int)arr.size(); ++i){
        if(ind[i] == ldsLen-1){
            if(!first) cout << "->";
            cout << bagToName[arr[i]];
            ldsLen--;
            first = false;
        }
    }

    return 0;
}
/** some test data
KinGboB 105 215 20 30 10
KinGboB 99 88 66 4599 787
Louis 777 999999 55 2 88
God 1 23 20 5 10
0 0

CRGhI 11534 12425 19785 4070 4645
MxHcR 13041 14113 10841 31046 23281
pTWZH 20687 7865 31387 4996 2765
DlQoy 8496 4322 32220 29103 22814
NcCYM 2396 26240 30528 10474 4827
ZnUzl 20202 32146 26732 26972 28738
QniLm 29949 31763 14693 13602 25727
XrhTd 4279 4350 14840 3726 31598
BKgaY 15089 25030 4574 32318 17366
Wwoqq 21821 8638 18178 6860 26841
0 0
**/
