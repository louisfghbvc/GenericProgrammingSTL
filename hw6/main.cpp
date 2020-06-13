#include <bits/stdc++.h>
using namespace std;

enum City{ TAIPEI, TAICHUNG, KAOHSIUNG, OTHER }; // Live in
enum Gender{ MALE, FEMALE};
enum Subject{ MATH, ENGLISH, CHINESE};

string getCity(City c){
    if(c == TAIPEI) return "Taipei";
    if(c == TAICHUNG) return "Taichung";
    if(c == KAOHSIUNG) return "Kaohsiung";
    return "Other";
}

City getCity(const string &s) {
    if(s == "Taipei") return TAIPEI;
    if(s == "Taichung") return TAICHUNG;
    if(s == "Kaohsiung") return KAOHSIUNG;
    return OTHER;
}

Gender getGender(const string &s) {
    if(s == "MALE") return MALE;
    if(s == "FEMALE") return FEMALE;
    throw "Error Gender Format";
    return FEMALE; // error return
}

string getGender(Gender g){
    if(g == MALE) return "MALE";
    return "FEMALE";
}

string getSubject(Subject s){
    if(s == MATH) return "Math";
    if(s == ENGLISH) return "English";
    return "Chinese";
}

class Person {
public:
    string firstName;
    string lastName;
    City city;
    string birthDay; // format as: 2020/09/28
    Gender gender;

    string showName() const {
        return "("+firstName+", "+lastName+")";
    }
};

class ScoreSheet {
public:
    int math; // math score 0~100
    int english; // english score 0~100
    int chinese; // chinese score 0~100
    double average; // 3 grade avg

    ScoreSheet(){ // constructor
        math = english = chinese = 0;
        average = 0.0;
    }

};

class Student {
public:
    string id; // ex: 405262180
    Person info;
    ScoreSheet scores;

    friend istream& operator>>(istream& is, Student &st){
        string city, gender;
        is >> st.id >> st.info.firstName >> st.info.lastName;
        is >> city >> st.info.birthDay >> gender;
        is >> st.scores.math >> st.scores.english >> st.scores.chinese;

        st.info.city = getCity(city);

        try{
            st.info.gender = getGender(gender);
        }catch(const string& err){
            cout << err << endl;
        }
        st.scores.average = (double)(st.scores.math+st.scores.english+st.scores.chinese)/3;

        return is;
    }

    friend ostream& operator<<(ostream& os, const Student& st){
        // example: 40428560  Mary Scot Taipei 2001/09/12  FEMALE 90 88 76
        os << st.id << " ";
        os << st.info.firstName << " " << st.info.lastName << " ";
        os << getCity(st.info.city) << " ";
        os << st.info.birthDay << " ";
        os << getGender(st.info.gender) << " ";
        os << st.scores.math << " " << st.scores.english << " " << st.scores.chinese;
        return os;
    }
};

// sort by ID and by birthDay descending
bool cmpIDAndBD(const Student &s1, const Student &s2){
    return s1.id < s2.id && s1.info.birthDay > s2.info.birthDay;
}

bool cmpAvg(const Student &s1, const Student &s2){
    return s1.scores.average > s2.scores.average;
}

int main()
{
    int n; // student nums
    cout << "Enter Student Numbers: \n";
    while(cin >> n){
        vector<Student> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];

        /**
        Q1, sort by ID increase and by birthDay descend,
        print Student name (FirstName, Last Name)
        **/
        cout << "Q1" << endl;
        sort(arr.begin(), arr.end(), cmpIDAndBD);
        for(const auto&s: arr){
            cout << s.info.showName() << endl;
        }

        /**
        Q2, list<Student> -> set<pair<string, city>>
        output city name
        **/
        cout << "\nQ2" << endl;
        set<pair<string, City> > st;
        for(int i = 0; i < n; ++i){
            st.insert({arr[i].info.showName(), arr[i].info.city});
        }
        for(const auto &x: st){
            cout << x.first << " " << getCity(x.second) << endl;
        }

        /**
        Q3, separate by city.
        map<city, list<Student>>
        **/
        cout << "\nQ3" << endl;
        map<City, vector<Student>> mp;
        for(const auto& x: arr){
            mp[x.info.city].push_back(x);
        }
        for(const auto &m : mp){
            cout << getCity(m.first) << endl;
            for(const auto &p : m.second){
                 cout << p.info.showName() << endl;
            }
        }

        /**
        Q4, separate by gender.
        map<gender, list<Student>>
        **/
        cout << "\nQ4" << endl;
        map<Gender, vector<Student>> mp2;
        for(const auto& x: arr){
            mp2[x.info.gender].push_back(x);
        }
        for(const auto &m : mp2){
            cout << getGender(m.first) << endl;
            for(const auto &p : m.second){
                 cout << p.info.showName() << endl;
            }
        }

        /**
        Q5, output each class, avg, min, max
        **/
        cout << "\nQ5" << endl;
        Student res, mn, mx; // total, min, max
        res = accumulate(arr.begin(), arr.end(), res, [](Student &a, Student &b){
                    a.scores.math += b.scores.math;
                    a.scores.english += b.scores.english;
                    a.scores.chinese += b.scores.chinese;
                    return a;
                });

        mn.scores.math = mn.scores.english = mn.scores.chinese = INT_MAX;
        mx.scores.math = mx.scores.english = mx.scores.chinese = INT_MIN;
        for_each(arr.begin(), arr.end(), [&](Student &s){
                    mn.scores.math = min(mn.scores.math, s.scores.math);
                    mn.scores.english = min(mn.scores.english, s.scores.english);
                    mn.scores.chinese = min(mn.scores.chinese, s.scores.chinese);
                    mx.scores.math = max(mx.scores.math, s.scores.math);
                    mx.scores.english = max(mx.scores.english, s.scores.english);
                    mx.scores.chinese = max(mx.scores.chinese, s.scores.chinese);
                 });

        cout << "math:\n";
        cout << "  avg: " << (double)res.scores.math/n << endl;
        cout << "  min: " << mn.scores.math << endl;
        cout << "  max: " << mx.scores.math << endl;
        cout << "english:\n";
        cout << "  avg: " << (double)res.scores.english/n << endl;
        cout << "  min: " << mn.scores.english << endl;
        cout << "  max: " << mx.scores.english << endl;
        cout << "chinese:\n";
        cout << "  avg: " << (double)res.scores.chinese/n << endl;
        cout << "  min: " << mn.scores.chinese << endl;
        cout << "  max: " << mx.scores.chinese << endl;

        /**
        Q6, for_each subject output not pass student
        map<Subject, map<bool, vector<Student>>> mp3
        **/
        cout << "\nQ6" << endl;
        map<Subject, map<bool, vector<Student> > > mp3;
        for(const auto& x: arr){
            mp3[MATH][(x.scores.math < 60)].push_back(x);
            mp3[ENGLISH][(x.scores.english < 60)].push_back(x);
            mp3[CHINESE][(x.scores.chinese < 60)].push_back(x);
        }
        for(auto& sub: mp3){
            cout << getSubject(sub.first) << endl;
            if(sub.second[true].size() <= 0){
                cout << "all pass !! \n";
            }
            else{
                for(auto& sd: sub.second[true]){
                    cout << sd.id << " " << sd.info.showName() << endl;
                }
            }
        }

        /**
        Q7 sort avg descend
        **/
        cout << "\nQ7" << endl;
        sort(arr.begin(), arr.end(), cmpAvg);
        for(auto &x : arr){
            cout << x.id << " " << x.info.showName() << " " << x.scores.average << endl;
        }
    }
    return 0;
}
/**
10
405262180 Louis Liu Taipei 1998/04/21 MALE 90 91 80
405262099 James Bond Taichung 2002/01/05 MALE 98 70 80
405261180 Mary Liu Kaohsiung 1999/02/20 FEMALE 95 61 89
405262096 James God  Taichung 2012/11/31 MALE 99 50 99
407262099 Who Biu  Taipei 2001/09/25 FEMALE 66 77 99
406261169 Lol Shoe  Taipei 2020/09/25 FEMALE 10 77 39
445251380 Cyc Game Kaohsiung 1998/12/20 MALE 65 88 85
435462096 James Min  Taichung 2012/11/31 MALE 97 54 19
409251387 Kevin dad Taipei 1997/04/11 FEMALE 45 61 57
404241091 Mori Zhone  Taichung 2002/07/15 MALE 89 58 49
**/
