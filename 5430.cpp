#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        int flag = 1, psize;
        string p, arr;
        deque<int> deq;
        cin >> p >> n >> arr;

        arr = arr.substr(1, arr.size()-2);
        if(arr.size() == 0){
            psize = p.size();
            for(int i = 0 ; i < psize; ++i){
                if(p[i] == 'D'){
                    flag = -1;
                    break;
                }
            }
        }
        else{
            string tmp;
            int asize = arr.size();
            for(int i = 0 ; i < asize; ++i){
                if(arr[i] == ','){
                    deq.push_back(stoi(tmp));
                    tmp.clear();
                }
                else{
                    tmp.push_back(arr[i]);
                }
            }
            deq.push_back(stoi(tmp));

            psize = p.size();
            for(int i = 0 ; i < psize; ++i){
                if(p[i] == 'R')
                    flag = flag == 1 ? 0 : 1;
                else{
                    if(deq.empty()){
                        flag = -1;
                        break;
                    }
                    if(flag)
                        deq.pop_front();
                    else
                        deq.pop_back();
                }
            }
        }
        
        if(flag == 1){
            if(deq.empty()){
                cout << "[]\n";
                continue;
            }
            deque<int>::iterator it;
            cout << "[";
            for(it = deq.begin(); it != deq.end()-1; ++it){
                cout << *it << ",";
            }
            cout << *it << "]\n";
        }
        else if(flag == 0){
            deque<int>::reverse_iterator it;
            cout << "[";
            for(it = deq.rbegin(); it != deq.rend()-1; ++it)
                cout << *it << ",";
            cout << *it << "]\n";
        }
        else{
            cout << "error\n";
        }
    }
}