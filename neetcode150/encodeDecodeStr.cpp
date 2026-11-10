#include<iostream>
#include<string>
#include<vector>

using namespace std;

string encode(vector<string>strs){
    string encodedStr;
    for(string s: strs){
        string len = to_string(s.size());
        string buffer = len + "#" + s;
        for(char &c : buffer){
            encodedStr.push_back(c);
        }
    }
    return encodedStr;
}

vector<string>decode(string s){

    vector<string>decodedStr;

    while(!s.empty()){
        string length;
        int k=0;
        while(s[k] != '#'){
            length.push_back(s[k]);
            k++;
        }
        int i = length.size()+1;
        int len = stoi(length) + length.size()+1;
        string buffer;
        for(i; i < len; i++){
            buffer.push_back(s[i]);
        }
        decodedStr.push_back(buffer);
        s.erase(0, len);
    }
    return decodedStr;

}

int main(){

    vector<string>listString = {"Hello","World"};

    string encoded = encode(listString);
    cout<<"Encoded: "<<encoded<<"\n";

    vector<string>decoded = decode(encoded);
    cout<<"[";
    for(int i=0; i<decoded.size(); i++){
        cout<<decoded[i];
        if(i!=decoded.size()-1){
            cout<<",";
        }
        else{
            cout<<"]";
        }
    }

    return 0;
}