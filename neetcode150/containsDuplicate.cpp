#include <iostream>
#include <unordered_set>
#include <vector>
//unorder set converts each of its entry into an hash and assigns a bucket to that hash so whenever the same element is pushed in the set it calculates the hash gets to the bucket number and as it laready has an element present it skips it and moves past it
using namespace std;
bool containsDuplicate(vector<int>nums);

int main(){

    vector<int>nums = {0,1,1,2,3,4,5};

    if(containsDuplicate(nums)){
        cout<<"True";
    }else{
        cout<<"false";
    }

    return 0;

}

bool containsDuplicate(vector<int>nums){
    unordered_set<int>seen;
    for (int num : nums){
        if(seen.count(num)){
          return true;
        }
        else{
            seen.insert(num);
        }
    }
    return false;
    
}