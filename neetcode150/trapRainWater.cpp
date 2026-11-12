#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int trapRain(vector<int>& height){
    int ans=0;
    int l=0;
    int r= height.size()-1;
    int leftMax = height[l];
    int rightMax = height[r];

    while(l<r){
        if(leftMax<rightMax){
            l++;
            leftMax = max(leftMax, height[l]);
            ans += leftMax - height[l];
        }else{
            r--;
            rightMax = max(rightMax, height[r]);
            ans += rightMax - height[r];
        }
    }
    return ans;
}

int main(){
    vector<int>height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trapRain(height); //6
    cout<<ans;
    return 0;
}