#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int>left(n, 1);
    vector<int>right(n, 1);
    vector<int>ans(n, 1);

    for(int i=1,j=n-2; i<n, j>=0; i++,j--){
        left[i] = left[i-1]*nums[i-1];
        right[j] = right[j+1]*nums[j+1];
    }

    for(int i=0; i<n; i++){
        ans[i] = left[i]*right[i];
    }
    return ans;
}

int main(){

    vector<int>nums = {1,2,4,6};
    vector<int>ans = productExceptSelf(nums);
    cout<<"[";
    for(int i=0; i< ans.size(); i++){
        cout<<ans[i];
        if(i == ans.size()-1){
            cout<<"]";
        }
        else{
            cout<<",";
        }
    }
    return 0;
}