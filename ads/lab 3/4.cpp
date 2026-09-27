#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number_of_enemies;
    cin>>number_of_enemies;
    vector <ll> power_of_enemies(number_of_enemies);
    vector <ll> sum(number_of_enemies+1,0);
    for(int i = 0; i<number_of_enemies; i++){
        cin>>power_of_enemies[i];
    }
    sort(power_of_enemies.begin(),power_of_enemies.end());
    for(int i = 0; i < number_of_enemies; ++i){
        sum[i + 1] = sum[i] + power_of_enemies[i];
    }
    int number_of_rounds;
    cin>>number_of_rounds;
    for(int i = 0; i<number_of_rounds;i++){
        ll power;
        cin>>power;
        auto it = upper_bound(power_of_enemies.begin(),power_of_enemies.end(),power);
        ll count = distance(power_of_enemies.begin(),it);
        ll sums = sum[count];
        cout<<count<<" "<<sums<<"\n";
    }
}