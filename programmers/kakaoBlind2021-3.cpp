#include <bits/stdc++.h>
using namespace std;

int options[4] = {3, 2, 2, 2};
int cache[3][2][2][2][100005];

int categorize(string token) {
    if(token == "-") return -1;
    
    if(token == "cpp") return 0;
    if(token == "java") return 1;
    if(token == "python") return 2;
    
    if(token == "backend") return 0;
    if(token == "frontend") return 1;
    
    if(token == "junior") return 0;
    if(token == "senior") return 1;
    
    if(token == "chicken") return 0;
    if(token == "pizza") return 1;
}

vector<int> splitInfo(string s) {
    vector<int> ret;
    size_t pos = 0;
    string token;
    while((pos = s.find(' ')) != string::npos) {
        token = s.substr(0, pos);
        ret.push_back(categorize(token));
        s.erase(0, pos + 1);
    }
    ret.push_back(stoi(s));
    return ret;
}

vector<int> splitQuery(string s) {
    vector<int> ret;
    size_t pos = 0;
    string delim = " and ";
    string token;
    while((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        ret.push_back(categorize(token));
        s.erase(0, pos + delim.length());
    }
    
    pos = s.find(' ');
    token = s.substr(0, pos);
    ret.push_back(categorize(token));
    s.erase(0, pos + 1);
    
    ret.push_back(stoi(s));
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string inf : info) {
        vector<int> res = splitInfo(inf);
        cache[res[0]][res[1]][res[2]][res[3]][res[4]]++;
    }
    
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                for(int l = 0; l < 2; ++l) {
                    for(int m = 1; m < 100005; ++m) {
                        cache[i][j][k][l][m] += cache[i][j][k][l][m-1];
                    }
                }
            }
        }
    }
    
    for(string q : query) {
        vector<int> res = splitQuery(q);
        
        vector<vector<int> > conditions;
        for(int i = 0; i < 4; ++i) {
            vector<int> v;
            if(res[i] == -1) {
                for(int j = 0; j < options[i]; ++j) {
                    v.push_back(j);
                }
            }
            else v.push_back(res[i]);
            conditions.push_back(v);
        }
        
        int count = 0;
        
        for(int lang : conditions[0]) {
            for(int role : conditions[1]) {
                for(int ex : conditions[2]) {
                    for(int food : conditions[3]) {
                        count += cache[lang][role][ex][food][100000] - cache[lang][role][ex][food][res[4]-1];
                    }
                }
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}