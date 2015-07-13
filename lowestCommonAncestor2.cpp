#include<queue>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *CreateTree(){
	queue<TreeNode*>q;
	int a[]={1,2,3,4,5,6,4};
	vector<int> arry;
	for(auto &x:a){
		arry.push_back(x);
	}
	TreeNode* root=new TreeNode(arry[0]);
	q.push(root);
	int count=1;
	while(1){
		if(count<arry.size()){
			TreeNode*tmp=new TreeNode(arry[count++]);
			q.front()->left=tmp;
			q.push(tmp);
		}else {
			return root;
		}

		if(count<arry.size()){
			TreeNode*tmp=new TreeNode(arry[count++]);
			q.front()->right=tmp;
			q.push(tmp);
		}else {
			return root;
		}
		q.pop();
	}
}

class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (!root) return NULL;
			if (root->val == p->val || root->val == q->val) return root;
			TreeNode *L = lowestCommonAncestor(root->left, p, q);
			TreeNode *R = lowestCommonAncestor(root->right, p, q);
			if (L && R) return root;  // if p and q are on both sides
			return L ? L : R;  // either one of p,q is on one side OR p,q is not in L&R subtrees
		}

};
int main(){
	TreeNode *root=CreateTree();
	Solution s;
	TreeNode* lcn=s.lowestCommonAncestor(root,new TreeNode(4),new TreeNode(5));
	cout<<lcn->val;
	return 0;
}
