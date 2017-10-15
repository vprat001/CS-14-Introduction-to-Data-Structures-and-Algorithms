#include <iostream>	
#include "stack.cc"
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

void RPN(string p) {
Stack<int> S;

for(unsigned i = 0; i < p.length(); ++i) {

	if((p[i] >= 0x30) && (p[i] <= 0x39)) 
	{

		int t = p[i] - 0x30;
		S.push(t);
		
	}
	else 
	{
	
	   	try {
			if(S.is_empty()) 
			{
				throw std::underflow_error("Underflow");			
			}
			else	
			{
			        int b = S.top(); 
				S.pop();
				if (S.is_empty())
				{
					throw std::underflow_error("underflow 2nd");
				}        
				else {
				
				if (p[i] == '+') 
				{				
				        int a = S.top();
					S.pop();
					int add = b + a;	
					S.push(add);
				}
				else if (p[i] == '-') 
				{
					int a = S.top();
                                        S.pop();
					int subtract = a - b;
					S.push(subtract);
				}
				else if (p[i] == '*') 
				{
					int a = S.top();
                                        S.pop();
					int multiply = b * a;
                        		S.push(multiply);
				}
				else if (p[i] == '/')
				{
					int a = S.top();
                                        S.pop();
					int divide = a / b;
                       	 		S.push(divide);
				}
				}
			}
		}
		catch (underflow_error& excpt)
                {
                        excpt.what();
                }


	}

}


int v = S.top();
S.pop();

if (!S.is_empty()) 
{
	throw overflow_error("recheck expression ");
}	
cout << v << endl;

	

}
int main() {
	ifstream inFS;
	int nums;
	string strings;
	Stack<int> N;
        Stack<string> S;

	inFS.open("file.txt");
	if(!inFS.is_open()) {
		cout << "Error opening file.txt " << endl;
		exit(1);
	}
	while(inFS >> nums) 
	{
		if(inFS.good()) {
			N.push(nums);
		}
	}
	inFS.close();
	N.pop();
        N.pop();
	N.push(20);
	N.push(7);
	cout << "Top of Stack N: " << N.top() << endl;
	
	
	inFS.open("stringfile.txt");
	if(!inFS.is_open()) {
		cout << "ERROR OPENING stringfile.txt " << endl;
		exit(1);
	}
	while(inFS >> strings)
	{
		if(inFS.good()) {
			S.push(strings);
		}
	}
	inFS.close();
	S.pop();	
	cout << "Top of Stack S: " << S.top() << endl;

	string okay = "91+";
	cout << "RPN Result for postfix string '987+3*9/-' is: ";
	S.print();
	RPN(okay);
}

	
