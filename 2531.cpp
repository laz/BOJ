#include <cstdio>
#include <set>

using namespace std;

int main(){

    int sushi[30001], dishes[3001];
    int n, d, k, c, tmp, count=0, max=0;
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &sushi[i]);
    }
    for(int i = 0 ; i < k; i++){
        if(dishes[sushi[i]]==0){
            count++;
        }
        dishes[sushi[i]]++;
    }
    if(dishes[c]==0)max++;
    max=count;
    for(int i = 0; i < n; i++){
        tmp=i+k;
        //Loop
        if(tmp>=n)tmp-=n;
        if(dishes[sushi[tmp]]==0){
            count++;
        }
        dishes[sushi[tmp]]++;
        dishes[sushi[i]]--;
        if(dishes[sushi[i]]==0) count--;

        //Coupon
        if(dishes[c]==0){
            if(max<count+1) max=count+1;
        } 
        else{
            if(max<count) max=count;
        }
    }

    printf("%d\n", max);

}