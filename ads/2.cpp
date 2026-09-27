#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector <ll> v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    for(int i = 0; i<m;i++){
        ll r1,l1,r2,l2;
        cin>>l1>>r1>>l2>>r2;
        int count = 0;
        for(int c = 0;c<n;c++){
            bool inf = (v[c]>=l1 && v[c]<=r1);
                        bool ins = (v[c]>=l2 && v[c]<=r2);
            if(inf || ins ) count++;
        }
        cout<<count<<endl;
    }
}