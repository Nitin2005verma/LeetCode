class Solution {
    unordered_map<char,vector<char>>mp;
void populateMap() {
    mp['2']={'a','b','c'};
    mp['3']={'d','e','f'};
    mp['4']={'g','h','i'};
    mp['5']={'j','k','l'};
    mp['6']={'m','n','o'};
    mp['7']={'p','q','r','s'};
    mp['8']={'t','u','v'};
    mp['9']={'w','x','y','z'};
}
void helper(vector<string>&ans, string up, string p){
    populateMap();
    if(up==""){
        ans.push_back(p);
    }
    for(auto el: mp[up[0]]){
        helper(ans,up.substr(1),p+el);
    }
}
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
        vector<string>ans;
    string temp;
    helper(ans,digits,"");
    return ans;
        
    }
};
