#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

string sortCharByFreq (string &s){
    unordered_map<char,int>freq;
    for(char c:s){
        freq[c]++;
    }
    priority_queue<pair<int,char>>pq;
    for(auto &pair : freq){
        pq.push({pair.second, pair.first});
    }
    string res;
    while(!pq.empty()){
        for(int i=0; i< pq.top().first; i++){
            res.push_back(pq.top().second);
        }
        pq.pop();
    }
    return res;
}

int main(){

    string s = "tree";
    string ans = sortCharByFreq(s);
    for(int i=0; i< ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}