class Solution {
public:
bool check(vector<int> cits,int k){
    int cnt=0;
    for(int i=0 ; i<cits.size(); i++){
        if(cits[i]>=k){
            cnt++;
        }
    }
    if(cnt>=k){
        return true;
    }
    return false;
}
    int hIndex(vector<int>& cits) {
        int n=cits.size();
        int hmin=0 ;
        auto it=max_element(cits.begin(),cits.end());
        int hmax=*it;
        for (int i=hmax; i>=hmin; i--){
            if(check(cits,i)==true){
                return i;
            }
        }
        return 0;
    }
};
