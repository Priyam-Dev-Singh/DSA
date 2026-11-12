#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfit(vector<int>& prices){
    int ans=0;
    int buy=prices[0];
    for(int i=0; i<prices.size(); i++){
        buy = min(buy, prices[i]);
        ans = max(ans, prices[i]-buy);
    }
    return ans;
}

int main(){
    vector<int>prices={10,1,5,6,7,1};
    int ans = maxProfit(prices);
    cout<<ans;
    return 0;
}