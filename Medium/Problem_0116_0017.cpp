class Solution {
    vector<vector<Node*>> print_level(Node*root){
        queue<Node*>Q;
        vector<vector<Node*>>ans;
        if(!root)return ans;
        Q.push(root);
        while(!Q.empty()){
            int n=Q.size();
            vector<Node*>temp;
            for(int i=0 ; i<n; i++){
                Node*curr = Q.front();
                temp.push_back(curr);
                if(curr->left)Q.push(curr->left);
                if(curr->right)Q.push(curr->right);
                Q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> res = print_level(root);
        for(auto arr: res){
            for(int i=0 ;  i<arr.size()-1; i++){
                arr[i]->next=arr[i+1];
            }
        }
        return root;
    }
};
