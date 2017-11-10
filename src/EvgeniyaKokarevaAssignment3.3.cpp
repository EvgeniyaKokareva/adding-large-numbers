#include "LinkedStack.h"
#include <iostream>
using namespace std;


string sum(string, string);
bool checkNumberInput(string);
string getInput();

int main() {

	//enter parameters
	string n1 = getInput();
	string n2 = getInput();

	//count sum and output to console
	cout << "sum = " << sum(n1, n2) << endl;

	return 0;
}

string sum (string firstNumber, string secondNumber){
	LinkedStack<int> n1;
	LinkedStack<int> n2;
	LinkedStack<int> sum;
	string result;

	//add the numbers from first input to the stack
	for(int i = 0; i < firstNumber.length(); i++){
		int num = firstNumber[i] - '0';
		cout<<num<<endl;
		n1.push(num);
	}

	//add the numbers from second input to the stack
	for(int i = 0; i < secondNumber.length(); i++){
		int num = secondNumber[i] - '0';
		n2.push(num);
	}

	int temp = 0;

	//addition
	while(n1.isEmpty() == false || n2.isEmpty() == false){
		int first = 0;
		int second = 0;

		//of stack is not ampty - change the digit from 0 to extracted number
		if(n1.isEmpty() == false){
			first = n1.pop();
		}

		if(n2.isEmpty() == false){
			second = n2.pop();
		}


		temp = temp + first + second;
		int temp2 = temp % 10;
		sum.push(temp2);

		//save tens for next addition
		temp = temp/10;

	}

	//convert stack of integers to string
	while(sum.isEmpty() == false){
		result += '0'+ sum.pop();
	}

	return result;
}

//check input for non-numeric
bool checkNumberInput(string input){
	bool isGoodInput = true;
		for(uint i = 0; i < input.length(); i++){
			if(isalpha(input[i])){
				isGoodInput = false;
				break;
			}
		}
		return isGoodInput;
}

//get and verify input
string getInput(){
	bool goodInput = false;
	string number;
	while(goodInput == false){
		cout << "Enter a very large number: ";
		cin>>number;
		goodInput = checkNumberInput(number);
		if(goodInput == false){
			cout << "wrong input. try again" << endl;
		}
	}
	return number;
}
