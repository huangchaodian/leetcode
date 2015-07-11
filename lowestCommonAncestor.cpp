#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if(root->val==p->val||root->val==q->val)return root;
			if(root->val<p->val&&root->val<q->val){
				return lowestCommonAncestor(root->right,p,q);
			}else if(root->val>p->val&&root->val>q->val){
				return lowestCommonAncestor(root->left,p,q);
			}else{
				return root;
			}
		}
};
TreeNode *CreateTreeBy(){
	queue<TreeNode*>q;
	int a[]={5,3,6,2,4,-1,-1,1};
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
void printTree(TreeNode *root){
	if(!root)return;
	printTree(root->left);
	cout<<root->val;
	printTree(root->right);
}
int main(){
	TreeNode* root=CreateTreeBy();
	printTree(root);
	Solution s;
	s.lowestCommonAncestor(root,new TreeNode(1),new TreeNode(4));
	return 0;
}
