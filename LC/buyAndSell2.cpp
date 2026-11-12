#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfit2(vector<int>& prices){
    int ans = 0;
    for(int i=0; i<prices.size()-1; i++){
        int buffer = prices[i+1]-prices[i];
        if(prices[i+1]-prices[i]>0){
            ans += buffer;
        }
    }
    return ans;
}

int main(){
    vector<int>prices = {7,1,5,3,6,4};
    int ans = maxProfit2(prices);
    cout<<ans;
    return 0;
}