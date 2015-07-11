#include<stack>
using namespace std;
class Queue{
	public:
		stack<int>s1;
		stack<int>s2;
		void push(int x){
			s1.push(x);
		}
		void pop(void){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());s1.pop();
				}
			}
			s2.pop();
		}
		int peek(void ){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());s1.pop();
				}
			}
			return s2.top();
		}
		bool empty(void){
			return s1.empty()&&s2.empty();
		}
};
