#include<iostream>
#include<string>
using namespace std;

bool helper(const char *s,const char *p){
	if(*p=='\0')return *s=='\0';
	if(*(p+1)!='*'){
		if(*s!=0&&(*s==*p||*p=='.')){
			return helper(s+1,p+1);
		}else return false;

	}else {
		while(*s!=0&&(*s==*p||*p=='.')){
			if(helper(s,p+2))return true;
			s++;
		}
		return helper(s,p+2);
		
	}

}


bool isMatch(string s, string p) {
	return helper(s.c_str(),p.c_str());
	
}
int main(){
	string s="aab",p="c*a*b";
	cout<<isMatch(s,p);
	return 0;
}
