#include <bits/stdc++.h>
using namespace std;

int cache[360005];

int timeToInt(string s) {
    return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
}

string intToTime(int time) {
    string hr = to_string(time/3600);
    string min = to_string(time/60%60);
    string sec = to_string(time%60);
    
    if(hr.length() == 1) hr = '0' + hr;
    if(min.length() == 1) min = '0' + min;
    if(sec.length() == 1) sec = '0' + sec;
    
    return hr + ':' + min + ':' + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    memset(cache, 0, sizeof(cache));
    
    int n = timeToInt(play_time);
    int ad = timeToInt(adv_time);
    
    for(string log : logs) {
        int from = timeToInt(log.substr(0, 8));
        int to = timeToInt(log.substr(9, 8));
        
        for(int i = from; i < to; ++i) {
            cache[i]++;
        }
    }
    
    long long sum = 0;
    for(int i = 0; i < ad; ++i) {
        sum += cache[i];
    }
    
    long long max = sum;
    int mIdx = 0;
    
    for(int i = ad; i < n; ++i) {
        sum -= cache[i-ad];
        sum += cache[i];
        
        if(sum > max) {
            max = sum;
            mIdx = i-ad+1;
        }
    }

    return intToTime(mIdx);
}