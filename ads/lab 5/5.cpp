#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    priority_queue<int, vector<int>, greater<int>> p;
    ll sum = 0;
    for(int i = 0;i<n;i++){
        string command;
        cin>>command;
        if(command == "print"){
            cout<<sum<<"\n";
        }
        else if(command == "insert"){
            int x;
            cin>>x;

            if(p.size()<k){
                p.push(x);
                sum+=x;
            }
            else if(x>p.top()){
                sum-=p.top();
                sum+=x;
                p.pop();
                p.push(x);
            }
        }
    }
}