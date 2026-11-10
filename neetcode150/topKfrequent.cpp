#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k){

    unordered_map<int,int>freq;
    for(int num:nums){
        freq[num]++;
    }

    priority_queue<pair<int,int>>pq;
    for(auto &pair : freq){
        pq.push({pair.second, pair.first});
    }
    vector<int>ans;
    for(int i=0; i<k; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;

}

int main(){

    vector<int>nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        
        cout<<ans[i];
        if(i != ans.size()-1){
            cout<<",";
        }
        else{
            cout<<"]";
        }
    }

}
