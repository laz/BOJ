#include <iostream>
#include <string>
using namespace std;

int que[2000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c, n, head = 0, tail = 0;
    cin >> c;
    string op;
    while(c--){
        cin >> op;
        if(op == "push"){
            cin >> n;
            que[tail++] = n;
        }
        else if(op == "pop"){
            if(head == tail){
                cout << -1 << "\n";
                continue;
            }
            cout << que[head] << "\n";
            que[head++] = 0;
        }
        else if(op == "front"){
            if(head == tail){
                cout << -1 << "\n";
                continue;
            }
            cout << que[head] << "\n";
        }
        else if(op == "back"){
            if(head == tail){
                cout << -1 << "\n";
                continue;
            }
            cout << que[tail-1] << "\n";
        }
        else if(op == "size")
            cout << tail-head << "\n";
        else if(op == "empty"){
            if(head == tail) cout << "1\n";
            else cout << "0\n";
        }
    }
}