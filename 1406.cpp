#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;

    list<char> l;
    for(auto ch : s){
        l.push_back(ch);
    }

    list<char>::iterator it = l.end();
    char ch, op;
    for(int i = 0; i < n; ++i){
        cin >> op;
        if(op == 'L'){
            if(it != l.begin()) --it;
        }
        else if(op == 'D'){
            if(it != l.end()) ++it;
        }
        else if(op == 'B'){
            if(it != l.begin()){
                --it;
                it = l.erase(it);
            }
        }
        else{
            cin >> ch;
            l.insert(it, ch);
        }
    }

    for(auto ch : l)
        cout << ch;
}