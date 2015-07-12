#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
class Solution{
	public:
		stack<char>op;
		stack<int>data;
		int calculate(string s){
			string num;
			auto eval=[](stack<char>&temop,stack<int>&temdata){
				while(!temop.empty()){
					if(temop.top()=='+'){
						temop.pop();
						int a=temdata.top();temdata.pop();
						int b=temdata.top();temdata.pop();
						temdata.push(a+b);
					}else if(temop.top()=='-'){
						temop.pop();
						int a=temdata.top();temdata.pop();
						int b=temdata.top();temdata.pop();
						temdata.push(a-b);
					}	
				}
				return temdata.top();
			};
			for(auto x:s){
				if(x==' '){continue;}
				if(x>='0'&&x<='9'){
					num+=x;
				}else if(num.size()>0){
					int tmp;
					stringstream ss;
					ss<<num;ss>>tmp;
					data.push(tmp);
//					cout<<tmp<<endl;
					num.clear();
				}
				if(x=='+'||x=='-'||x=='('){op.push(x);}
				if(x==')'){
					stack<char>temop;
					stack<int>temdata;
					temdata.push(data.top());data.pop();
					while(op.top()!='('){
						temop.push(op.top());op.pop();
						temdata.push(data.top());data.pop();
					}
					data.push(eval(temop,temdata));
					op.pop();
				}
			}
			if(num.size()>0){
				int tmp;
				stringstream ss;
				ss<<num;ss>>tmp;
				data.push(tmp);
				num.clear();
			}
			stack<char>temop;
			stack<int>temdata;
			temdata.push(data.top());data.pop();
			while(!op.empty()){
				temop.push(op.top());op.pop();
				temdata.push(data.top());data.pop();
			}
			data.push(eval(temop,temdata));
			return data.top();
		}
};
int main(){
	Solution s;
	string str="4-5+2";
	cout<<str+"="<<s.calculate(str);

	return 0;
}
