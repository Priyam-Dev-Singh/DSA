#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> validTwoSum(vector<int>nums, int target){
    
    unordered_map<int, int>map;

    for(int i=0; i<nums.size(); i++){
        int diff = target - nums[i];

        if(map.count(diff)){
            return {map[diff], i};
        }
        map[nums[i]] = i;
    }
    return {0};
}

int main(){
    int target = 7;
    vector<int>nums = {3,4,6,7};
    vector<int>sol = validTwoSum(nums, target);

    if(sol.size()==2){
        cout<< "{" << sol[0] << "," << sol[1] << "}";
    }
    else if(sol.size() == 1){
        cout<<"There exists no valid two sum";
    }

    return 0;
}
