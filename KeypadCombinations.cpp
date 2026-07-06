#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>keypad={
    {},
    {},
    {"abc"},
    {"def"},
    {"ghi"},
    {"jkl"},
    {"mno"},
    {"pqrs"},
    {"tuv"},
    {"wxyz"}
};
void helper(string input,int pos,int n,string ans){
    if(pos==n){
        cout<<ans<<endl;
    }
    else{
        int digit=input[pos]-'0';
        for(int i=0;i<keypad[digit].size();i++){
        ans.push_back(keypad[digit][i]);
        helper(input,pos+1,n,ans);
        ans.pop_back();
        }
    }
}
void letterCombinations(string input){
    int n=input.size();
    if(n==0){
        cout<<"No number pressed .";
        return;
    }
    helper(input,0,n,"");

}
int main(){
letterCombinations("25");

return 0;    
}