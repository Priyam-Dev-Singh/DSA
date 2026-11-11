#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int contWithMostWater(vector<int> &height){
    int l = 0;
    int r = height.size()-1;
    int ans = 0;
    while(l<r){
        ans = max(ans, min(height[l], height[r])*(r-l));

        height[l]<height[r]?l++:r--;
    }
    return ans;
}

int main(){
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    int ans = contWithMostWater(height);
    cout<<ans;
    return 0;
}