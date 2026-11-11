#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSumII(vector<int> &nums, int &target){

    int l=0, r = nums.size()-1;
    while (l<r)
    {
        int sum = nums[l]+nums[r];
        if(sum>target) r--;
        else if(sum<target) l++;
        else return {l+1, r+1};
    }
    return {0};

}

int main(){
    vector<int>nums = {1,7,11,15};
    int target = 9;
    vector<int>ans = twoSumII(nums,target);
    if(ans.size()==1){
        cout<<"No sol exists";
    }
    else cout<<"["<<ans[0]<<","<<ans[1]<<"]";
   
    return 0;
}