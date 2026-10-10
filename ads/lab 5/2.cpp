#include <iostream>
#include <queue>
#include <vector>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<int> p(v.begin(),v.end());
    while(p.size()>1){
        int f = p.top();
        p.pop();
        int s = p.top();
        p.pop();
        if(f!=s){
            p.push(abs(f-s));
        }
    }
    cout<<(p.empty() ? 0 : p.top());
}