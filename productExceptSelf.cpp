vector<int> productExceptSelf(vector<int>& nums) {
	for (auto x : nums) { cout << x << " "; }cout <<"----nums"<< endl;
	vector<int>ans(nums.size(),1),ans2(nums.size(),1);
	partial_sum(nums.begin(), nums.end()-1, ans.begin()+1, [](int a, int b) {return a*b;});
	for_each(ans.begin(), ans.end(), [](int a) {cout << a << " ";});cout <<"----ans1"<< endl;

	reverse(nums.begin(),nums.end());
	for (auto x : nums) { cout << x << " "; }cout <<"---reverse-nums"<< endl;
	partial_sum(nums.begin(), nums.end()-1, ans2.begin()+1, [](int a, int b) {return a*b;});
	for_each(ans2.begin(), ans2.end(), [](int a) {cout << a << " ";});cout <<"-----ans2"<< endl;

	reverse(ans2.begin(),ans2.end());
	transform(ans.begin(), ans.end(), ans2.begin(), ans.begin(), [](int a, int b) {return a*b;});

	return ans;
}
