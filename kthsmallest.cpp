#Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
#
#Note: 
#You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
u
#include<iostream>
#include<functional>
sing namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int kthSmallest(TreeNode* root, int k) {
			int ans;
			function<void(TreeNode*)> rec=[&](TreeNode* root){
					if(!root)return ;
					if(k>=0){
						rec(root->left);
						if(--k==0){
							ans=root->val;
						}
						rec(root->right);
					}
			}
			rec(root);
			return ans;
		}
};
int main(){
	Solution s;
	return 0;
}
