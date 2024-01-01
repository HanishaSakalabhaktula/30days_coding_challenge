#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
        if(!b) return a;
        return gcd(b, a%b);
    }
    int lcm(long long a, long long b){
        long long temp = (a / (gcd(a, b))) * b;

        return temp > INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int s = 1;
        int e = INT_MAX;
        int l = lcm(divisor1, divisor2);

        while(s <= e){
            int mid = s + (e-s)/2;
            int a = mid - (mid/divisor1);
            int b = mid - (mid/divisor2);
            int c = mid - (mid/l);

            if(a >= uniqueCnt1 and b >= uniqueCnt2 and c >= (uniqueCnt1 + uniqueCnt2)){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return s;
    }
int main(){
    int d1, d2, u1, u2;
    cin>>d1>>d2>>u1>>u2;
    cout<<minimizeSet(d1,d2,u1, u2);
    return 0;
}