#include<iostream>
#include<string>

using namespace std;

bool validPalindrome(string s){
    int left = 0;
    int right = s.size()-1;

    while(left < right){

        while(!isalnum(s[left]) && left < right) left++;
        while(!isalnum(s[right]) && left < right) right--;

        if(tolower(s[left]) != tolower(s[right]) && left<right) return false;

        left++;
        right--;
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    bool ans = validPalindrome(s);
    ans ? cout<<"True": cout<<"False";
    return 0;
}