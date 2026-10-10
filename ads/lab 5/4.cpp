#include <iostream>
#include <cstdint>
#include <queue>
#include <vector>
using u = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    u n,k;
    cin>>n>>k;
    vector<u> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    int oper = 0;
    priority_queue<u, vector<u>,greater<u>> p(v.begin(),v.end());
    while(p.size()>0 && p.top() < k){
        if(p.size()<2){
            cout<<-1<<"\n";
            return 0;
        }
        u least = p.top();
        p.pop();
        u sleast = p.top();
        p.pop();
        u density = least+(2LL*sleast);
        p.push(density);
        oper++;
    }
    cout<<oper;
}