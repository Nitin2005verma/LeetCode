class Solution {
    
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> ans;
        int rsi,rei,csi,cei;
        rsi=0; rei=n-1; csi=0; cei=m-1;
        while(rsi<=rei && csi<=cei){
            for(int i=rsi ; i<=rei; i++){
                ans.push_back(mat[csi][i]);
            }
            csi++;
            if(rsi >rei || csi >cei)break;
            for(int i=csi ; i<=cei; i++){
                ans.push_back(mat[i][rei]);
            }
            rei--;
            if(rsi >rei || csi >cei)break;
            for(int i=rei ; i>=rsi; i--){
                ans.push_back(mat[cei][i]);
            }
            cei--;
            if(rsi >rei || csi >cei)break;
            for(int i=cei ; i>=csi; i--){
                ans.push_back(mat[i][rsi]);
            }
            rsi++;
            if(rsi >rei || csi >cei)break;
        }
        return ans;
    }
};
