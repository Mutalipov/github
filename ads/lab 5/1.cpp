#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<ll, vector<ll>,greater<ll>> p(v.begin(),v.end());
    ll total = 0;
    while(p.size()>1){
        ll f = p.top();
        p.pop();
        ll s = p.top();
        p.pop();
        ll cur = f+s;
        total+=cur;
        p.push(cur);
    }
    cout<<total;
}