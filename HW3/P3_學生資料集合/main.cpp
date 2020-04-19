#include <bits/stdc++.h>

using namespace std;

class Student{
    string name;
    int english;
    int math;

    friend istream& operator>>(istream& is, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);
    friend bool operator<(const Student& s1, const Student& s2);
};

class RuntimeCmp{
    public:
        enum cmp_mode {normal, reverse};
    private:
        cmp_mode mode;
    public:
        RuntimeCmp(cmp_mode m= normal) : mode(m) {}
        template<typename T>
        bool operator()(const T& t1, const T& t2) const{
           return mode==normal ? t1 < t2 : t2 < t1;
        }
        bool operator==(const RuntimeCmp& rc) const{
            return mode == rc.mode;
        }
};

//overload input
istream& operator>>(istream& is, Student &s){
    is >> s.name >> s.english >> s.math;
    return is;
}

//overload output
ostream& operator<<(ostream& out, const Student &s){
    out << s.name << " " << s.english << " " << s.math;
    return out;
}

//overload less
bool operator<(const Student &s1, const Student &s2){
    int s1_sum = s1.english + s1.math;
    int s2_sum = s2.english + s2.math;
    if(s1_sum == s2_sum)
        return s1.name < s2.name;
    return s1_sum < s2_sum;
}

int main()
{
    int n;
    cin >> n;

    set<Student, RuntimeCmp> A;

    set<Student, RuntimeCmp> B(RuntimeCmp(RuntimeCmp::reverse));

    for(int i = 0; i < n; ++i){
        Student tmp;
        cin >> tmp;
        A.insert(tmp);
        B.insert(tmp);
    }

    cout << "Set A:\n";
    for(auto member : A){
        cout << member << endl;
    }

    cout << "\nSet B:\n";
    for(auto member : B){
        cout << member << endl;
    }
    return 0;
}
/*
5
Adam 98 90
Charles 80 85
Patrick 100 88
Peter 100 100
Hulk 94 94
*/

