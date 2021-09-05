#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    
    for(char c : new_id) {
        if(!isalnum(c) && c != '-' && c != '_' && c != '.') continue;
        tmp += tolower(c);
    }
    
    for(char c : tmp) {
        if(answer != "" && answer.back() == '.' && c == '.') continue;
        answer.push_back(c);
    }
    
    answer = answer.substr(answer[0] == '.' ? 1 : 0);
    if(answer.back() == '.') answer.pop_back();
    
    if(answer == "") answer.push_back('a');
    
    if(answer.length() >= 16) answer = answer.substr(0, 15);
    
    if(answer.back() == '.') answer.pop_back();
    
    if(answer.length() <= 2) {
        char c = answer.back();
        while(answer.length() != 3) answer.push_back(c);
    }
    
    return answer;
}