#include <iostream>
#include <string>
using namespace std;

int deque[20002];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
     int c, n, front = 10000, back = 10001;
     cin >> c;
     string op;
     while(c--){
         cin >> op;
         if(op == "push_front"){
             cin >> n;
             deque[front--] = n;
         }
         else if(op == "push_back"){
             cin >> n;
             deque[back++] = n;
         }
        else if(op == "front"){
            if(front+1 == back) cout << "-1\n";
            else cout << deque[front+1] << "\n";
        }
        else if(op == "back"){
            if(front+1 == back) cout << "-1\n";
            else cout << deque[back-1] << "\n";
        }
        else if(op == "pop_front"){
            if(front+1 == back){
                cout << "-1\n";
            }
            else{
                cout << deque[front+1] << "\n";
                front++;
            }
        }
        else if(op == "pop_back"){
            if(front+1 == back){
                cout << "-1\n";
            }
            else{
                cout << deque[back-1] << "\n";
                back--;
            }
        }
        else if(op == "size"){
            cout << back-front-1 << "\n";
        }
        else if(op == "empty"){
            if(front+1 == back) cout << "1\n";
            else cout <<"0\n";
        }
        
     }
}