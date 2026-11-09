#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

void printAnswer(vector<vector<string>> ans){
    cout<<"[ ";

    for(int i=0; i < ans.size(); i++){
        cout<<"[";
        vector<string>& mid = ans[i];
        for(int j=0; j<mid.size(); j++){
            if(j == mid.size()-1){
                cout<<mid[j];
            }
            else{
                cout<<mid[j]<<",";
            }
            
        }
        if(i==ans.size()-1){
            cout<<"]";
        }
        else{
            cout<<"], ";
        }
    }
    cout<<" ]";
}

void groupAnagrams(vector<string>strs){
    
    vector<vector<string>> ans;
    unordered_map<string,vector<string>>map;

    for(string s: strs){
        string key= s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    for(auto &pair : map){
        ans.push_back(pair.second);
    }

   printAnswer(ans);

}

int main(){
    vector<string>strs = {"act","pots","tops","cat","stop","hat"};
    
    groupAnagrams(strs);

    return 0;

}