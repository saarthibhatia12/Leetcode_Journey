class Solution {
    void markparents(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                parent[cur->left]=cur;
            }
            if(cur->right){
                q.push(cur->right);
                parent[cur->right]=cur;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markparents(root,target,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>queue;
        queue.push(target);
        visited[target]=true;
        int level=0;
        while(!queue.empty()){
            if(level++==k) break;
            int size=queue.size();
            for(int i=0;i<size;i++){
                TreeNode*cur=queue.front();
                queue.pop();
                if(cur->left && !visited[cur->left]){
                    queue.push(cur->left);
                    visited[cur->left]=true;
                }
                if(cur->right && !visited[cur->right]){
                    queue.push(cur->right);
                    visited[cur->right]=true;
                }
                if(parent[cur]&& !visited[parent[cur]]){
                    queue.push(parent[cur]);
                    visited[parent[cur]]=true;
                }
            }
        }
        vector<int>ans;
        while(!queue.empty()){
            TreeNode*cur=queue.front();
            queue.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};

// T.C.=O(2*N)
// S.C.=O(3*N)

// KEY TAKEAWAY
// ALWAYS REMEMBER WHENEVER WE BRACK TRAVERSE IN A TREE WE SHOULD FIRST MARK PARENT OF ALL NODES USING A HASHMAP

// Approach:
// Mark each node to its parent to traverse upwards
// We will do a BFS traversal starting from the target node
// As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
// when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result
