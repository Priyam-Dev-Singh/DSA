#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int longestSequence(vector<int>nums){
    if(nums.empty()) return 0;

    int ans = 1;
    
    unordered_set<int>numSet;
    for(int num: nums){
        numSet.insert(num);
    }
    for(int num: numSet){
        int buffer = 1;
         if(numSet.count(num-1)){
                continue;
        }
        else if(numSet.count(num+1)){
            int i=1;
            while(numSet.count(num+i)){
                buffer++;
                ans = max(ans,buffer);
                i++;
            }
        }
        else continue;
    }

    return ans;
}

int main(){

    vector<int>nums={100,1,2,3,0,99,98,97,96};
    int ans = longestSequence(nums);
    cout<<ans;
    return 0;

}