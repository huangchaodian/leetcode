#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	ListNode *reverse(ListNode* root){
		if(!root)return root;
		ListNode H(0);
		H.next=root;
		root=root->next;
		H.next->next=NULL;
		while(root){
			ListNode *tmp=root->next;
			root->next=H.next;
			H.next=root;
			root=tmp;
		}
		return H.next;
	}
	ListNode* split(ListNode*root,int len){
		while(--len){
			root=root->next;
		}
		ListNode*other=root->next;
		root->next=NULL;
		return other;
	}
	print(ListNode*root){
		while(root){
			cout<<root->val<<" ";
			root=root->next;
		}
	}

	public:
	bool isPalindrome(ListNode* head) {
		int len=0;
		for(auto it=head;it!=NULL;it=it->next){
			len++;
		}
		ListNode* other=split(head,len/2);
		cout<<endl<<"other :";
		print(other);
		cout<<endl<<"before reverse :";
		print(head);
		head=reverse(head);
		cout<<endl<<"after head :";
		print(head);
		if(len%2==1)other=other->next;
		while(head){
			if(head->val!=other->val){
				return false;
			}
			head=head->next;
			other=other->next;
		}
		return true;
	}
};
int main(){
	int l[]={-31900,22571,-31634,19735,13748,16612,-28299,-16628,9614,-14444,-14444,9614,-16628,-31900,16612,13748,19735,-31634,22571,-28299};
//	int l[]={1,2,2,1};
	ListNode H(0);
	ListNode*root;root=&H;
	cout<<"data:";
	for(auto &x:l){
		root->next=new ListNode(x);
		root=root->next;
		cout<<x<<" ";
	}
	Solution s;
	cout<<endl<<"result "<<s.isPalindrome(H.next);
return 0;
}
