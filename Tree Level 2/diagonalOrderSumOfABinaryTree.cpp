#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

vector<int> diagonalOrderSum(TreeNode *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    // vector<vector<int>>diagonalOrder;
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()>0){
        int n=q.size();
        int sum=0;
        for(int i=0;i<n;i++){
            TreeNode* rem = q.front();
            q.pop();

            while(rem!=NULL){
                if(rem->left!=NULL){
                    q.push(rem->left);
                }
                sum += rem->val;
                rem = rem->right;
            }
        }
        ans.push_back(sum);
    }
    
    // for(vector<int>x:diagonalOrder){
    //     int sum=0;
    //     for(int i=0;i<x.size();i++){
    //         sum += x[i];
    //     }
    //     ans.push_back(sum);
    // }
    return ans;
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    vector<int> ans = diagonalOrderSum(root);
    int idx = 0;
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}
