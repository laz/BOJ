#include <iostream>
using namespace std;

bool arr[1000001];

int main(){
    string p; int k; cin >> p >> k;
    for(int i = 2; i < k; ++i){
        if(!arr[i]){
            int mod = 0;
            for(int j = 0; p[j]; ++j)
                mod = (mod*10 + (p[j]-'0')) % i;
            if(mod == 0){
                cout << "BAD " << i;
                return 0;
            }
            for(int j = i*2; j <= k; j+=i)
                arr[j] = true;
        }
    }
    cout << "GOOD";
}