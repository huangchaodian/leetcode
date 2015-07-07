#include<iostream>
#include<functional>
using namespace std;
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
	int a=0;
	std::function<int(int)> fib = [&](int n) -> int
	{
		a++;

		return (n<=2) ? (1) : (fib(n-1)+fib(n-2));

	};
	cout<<fib(13);
	return 0;
}
