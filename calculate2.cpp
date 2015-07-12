#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
class Solution{
	public:
		stack<char>op;
		stack<long>data;
		long calculate(string s){
			string num;
			auto evalX=[](stack<char>&temop,stack<long>&temdata){
				while(!temop.empty()){
					if(temop.top()=='*'){
						temop.pop();
						long a=temdata.top();temdata.pop();
						long b=temdata.top();temdata.pop();
						temdata.push(a*b);
					}else if(temop.top()=='/'){
						temop.pop();
						long a=temdata.top();temdata.pop();
						long b=temdata.top();temdata.pop();
						temdata.push(a/b);
					}else return;
				}
			};
			auto eval_=[](stack<char>&temop,stack<long>&temdata){
				while(!temop.empty()){
					if(temop.top()=='+'){
						temop.pop();
						long a=temdata.top();temdata.pop();
						long b=temdata.top();temdata.pop();
						temdata.push(a+b);
					}else if(temop.top()=='-'){
						temop.pop();
						long a=temdata.top();temdata.pop();
						long b=temdata.top();temdata.pop();
						temdata.push(a-b);
					}else return;
				}
			};

			for(auto x:s){
				if(x==' '){continue;}
				if(x>='0'&&x<='9'){
					num+=x;
				}else if(num.size()>0){
					long tmp;
					stringstream ss;
					ss<<num;ss>>tmp;
					data.push(tmp);
					num.clear();
				}
				if(x=='+'||x=='-'){
					stack<char>temop;
					stack<long>temdata;
					temdata.push(data.top());data.pop();
					while(!op.empty()&&(op.top()=='*'||op.top()=='/')){
						temop.push(op.top());op.pop();
						temdata.push(data.top());data.pop();
					}
					evalX(temop,temdata);
					op.push(x);
					data.push(temdata.top());
				}
				if(x=='*'||x=='/'){	op.push(x);}
			}
			if(num.size()>0){
				long tmp;
				stringstream ss;
				ss<<num;ss>>tmp;
				data.push(tmp);
				num.clear();
			}
			stack<char>temop;
			stack<long>temdata;
			temdata.push(data.top());data.pop();
			while(!op.empty()&&(op.top()=='*'||op.top()=='/')){
				temop.push(op.top());op.pop();
				temdata.push(data.top());data.pop();
			}
			evalX(temop,temdata);
			while(!op.empty()){
				temop.push(op.top());op.pop();
				temdata.push(data.top());data.pop();
			}
			eval_(temop,temdata);
			return temdata.top();
		}
};
int main(){
	Solution s;
	string str="3+2*2";
	cout<<str+"="<<s.calculate(str);

	return 0;
}
