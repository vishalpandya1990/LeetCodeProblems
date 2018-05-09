

class Solution {
public:
    typedef struct Node {
        int val;
        int freq;
        int count;
        Node *left, *right;
        Node(int val) {
            this->val = val;
            freq = 1;
            count = 0;
            left = right = NULL;
        }
    }Node;
    
    Node* insert(Node *root, int key, int& countOfSmaller) {
        if(!root) {
            countOfSmaller = 0;
            return new Node(key);
        }
        if(root->val == key) {
            root->freq += 1;
            countOfSmaller = root->count;
            return root;
        }
        if(root->val > key) {
            root->count += 1;
            root->left = insert(root->left, key, countOfSmaller);
            return root;
        }
        if(root->val < key) {
            root->right = insert(root->right, key, countOfSmaller);
            countOfSmaller += root->count + root->freq;
            return root;
        }
        return NULL;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            vector<int> res;
            return res;
        }
        vector<int> res(n);
        Node *root = NULL;
        for(int i = n-1; i >= 0; i--) {
            int count = 0;
            root = insert(root, nums[i], count);
            res[i] = count;
        }
        return res;
    
    }
    vector<int> _countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        if(n == 0) {
            vector<int> empty;
            return empty;
        }
        multiset<int> visited;
        res[n-1] = 0;
        visited.insert(nums[n-1]);
        for(int i = n-2; i >= 0; i--) {
            int key = nums[i];
            int count = 0;
            for(auto it = visited.begin(); it != visited.end(); it++) {
                if(*it >= key) {
                    break;
                } else {
                    count++;
                }
            }
            res[i] = count;
            visited.insert(key);
        }
        return res;
    }
};
