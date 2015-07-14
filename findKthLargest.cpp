#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			int L = 0, R = nums.size() - 1;
			while (L < R) {
				int left = L, right = R;
				int key = nums[left];
				while (left < right) {
					while (left < right && nums[right] < key) --right;
					nums[left] = nums[right];
					while (left < right && nums[left] >= key) ++left;
					nums[right] = nums[left];
				}
				nums[left] = key;
				if (left == k - 1) return nums[k - 1];
				else if (left > k - 1) R = left - 1;
				else L = left + 1;
			}
			return nums[k - 1];
		}
};
int main(){
	Solution s;
	int a[]={5,2,4,1,3,6,0 };
	vector<int>test;
	for(auto x:a){test.push_back(x);}
	for(auto x:a)cout<<x;cout<<endl;
	cout<<s.findKthLargest(test,2);
	return 0;
}
