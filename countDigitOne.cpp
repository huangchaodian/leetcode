class Solution{
	public:
		int countDigitOne(int n){
			int ans=0;
			for(long m=1;m<=n;m*=10){
				int a=n/m,b=n%m;
				ans+=a/10*m;
				if(a%10==1){
					ans+=b+1;
				}else if(a%10>1){
					ans+=m;
				}
			}
			return ans;
		}
};
