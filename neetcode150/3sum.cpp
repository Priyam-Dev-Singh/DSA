#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum (vector<int> & nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>>ans;

    for(int i=0; i<n; i++){

        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int l=i+1, r=n-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum<0){
                l++;
            }
            else if(sum>0){
                r--;
            }
            else{
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while(l<r && nums[l]==nums[l-1]) l++;
                while(l<r && nums[r]==nums[r+1]) r--;
            }
        }
    }
    return ans;
}

int main(){

    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>>ans = threeSum(nums);

    if(ans.empty()){
        cout<<"No valid 3 sum exists";
        return 0;
    }

    cout<<"[";
    for(int i=0; i<ans.size(); i++){

        cout<<"["<<ans[i][0]<<","<<ans[i][1]<<","<<ans[i][2]<<"]";
        if(i == ans.size()-1){
            cout<<"]";
        }
        else cout<<",";
    }

    return 0;
}