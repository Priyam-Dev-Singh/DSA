#include<iostream>
#include<unordered_map>
#include<string>
#include<cctype>
using namespace std;

//an unordered map maps a specific data type with another datatype. It is really useful in indentifying the frequency of specific things

bool validAnagram(string s, string t){
    unordered_map<char,int>map;
    for(char c:s){
        map[c]++;
    }
    for(char c:t){
        map[c]--;
        //another way for finding the answer if the length of strings are equal
        /* if(map[c]<0){
            return false;
        } */
    }
     for(auto& pair : map){ 
        if(pair.second!=0){
            return false;
        }
    }
   return true;
}

string lowerCase(string s){
    for(char& c: s){
        c = tolower(c);
    }
    return s;
}

int main(){

    string name = lowerCase("nanagram");
    string name2 = lowerCase("annagRa");
    
    
    validAnagram(name, name2)?cout<<"true":cout<<"false";
    return 0;
}