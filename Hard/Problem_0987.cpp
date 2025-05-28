/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void mark(TreeNode*root, int h ,int v,vector<pair<int,pair<int,TreeNode*>>>&arr){
    if(root==NULL)return;
    arr.push_back(make_pair(h, make_pair(v, root)));
    if(root->left)mark(root->left,h-1,v+1,arr);
    if(root->right)mark(root->right,h+1,v+1,arr);
    return;
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>>ans;
    vector<pair<int,pair<int,TreeNode*>>>arr;
    mark(root,0,0,arr);
    sort(arr.begin(),arr.end());
    int i=0 ; int n=arr.size();
    while(i<n){
        int j=i;
        multiset<pair<int,int>>st;
        while(j<n && arr[j].first == arr[i].first){
            st.insert(make_pair(arr[j].second.first, arr[j].second.second->val));
            j++;
        }
        vector<int>temp;
        for(auto it:st){
            temp.push_back(it.second);
        }
        ans.push_back(temp);
        i=j;
    }
    return ans;
    
        
}
};
