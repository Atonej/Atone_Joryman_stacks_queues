#include "functions.h"
#include <stack>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include <streambuf>
//#include <sstream>
/******************************************
 * This program will be able to use the 
 * balancing of symbols and encode them 
 * into postfix balancing 
 *
 * @author Atone Joryman
 * @version Winter 2018
 * ****************************************/




//int main(int argc , char* argv[]){
int main(){
std::cout << "enter the file name (i.e filename.txt) " << std::endl;
std::string  carryString;
//put input in string
 getline(std::cin, carryString);

std::cout << "If this file is for balancing symbols type letter [b] if this is a math expression type letter  [m] " << std::endl;
//get option of the filename
std::string option;
//until correct option was chosen
//getline(std::cin, option);

while(option != "m" &&  option != "b"){
option.clear();
getline(std::cin, option);
std::cout << "enter the letter m or b and press enter" << std::endl;
}

	//if space found, means there are more than one argument
	if(carryString.find(" ") != std::string::npos ){
		std::cout << "only input filename(one argument)" << std::endl;
		std::cout << carryString << std::endl;
	}

	else{

		
		bool balanced =false;	
		//declaring what holds the file to read
		std::ifstream fin (carryString);

		//check success
		if(!fin.is_open() ){
			std::cout << "Cannot Open" << std::endl;
			return 0;
		}

		
//check for input 
	//if(argc>0){
	//make input and put into string using stream buffer	
	std::string test((std::istreambuf_iterator<char>(fin)),
                 std::istreambuf_iterator<char>());
	//std::string test = "func() { if(balanced) return arr [11]; }  ";	
	//std::string test = " ( ";
	//perform when balancing symbols
	if(option == "b"){
		balanced = balancedSymbols(test);

		if(balanced){
		std::cout << "Your symbols are balanced: " << test << std::endl;
	
		}

		else{
		std::cout << "Your symbols are not balanced: " << test << std::endl;
	
		}
	}
	else{	
	//std::string infix = " 5 * 6 - (10 + 5) / 3 ";

	std::string postfix = iToP(test);

		std::cout << "Infix expression: " << test << std::endl;
		std::cout << "Postfix expression: " << postfix << std::endl;
	}	

	}
 
return 0;
}

/***************************************
 * This method will read if a corresponding
 * closing symbol is available in a string
 *
 * @param string that was inputted
 * @return the boolean result if balanced or not
 * **************************************/
bool balancedSymbols(std::string input){

//setup stack and in vector form
//std::stack<char, std::vector<char> > st;
std::stack<char, std::deque<char> > st;

bool balanced =false;		
		for(auto it = input.begin(); it != input.end(); ++it){
			if(*it == '(' || *it == '[' || *it == '{'){
				st.push(*it);
				//std::cout << "pushed" << std::endl;
			}
			else{
				if(*it == ')' ){//&& st.top() == ')'){
					st.pop();
				}

				if(*it == ']' ){//&& st.top() == ']'){
					st.pop();
				}

				if(*it == '}' ){//&& st.top() == '}'){
					st.pop();
				}

				
			}
			
			
		}
			if(st.empty())
				balanced = true;

return balanced;
}
/****************************************
 * This method will take in a string input
 * and return a string in its prefix 
 * expression
 *
 * @param string of the inputted message
 * @return the prefix of type string
 * **************************************/
std::string iToP(std::string input){
//std::vector<char> newinput;
//std::vector<char>::iterator it;
std::string postfix;
std::queue<char > qu;
	
	//put each letter into vector
	
	//pretty helpful for changing signs and inserting 
	//to a queue but not needed
	//for(unsigned int i = 0; i < input.size(); i++){
		
	//	qu.push(input.at(i));
		//std::cout << st << std::endl;	
	//}
//postfix  = newinput.begin();
	//get non operators first
	for(auto it = input.begin(); it != input.end(); ++it){
		if((*it != '(') && (*it != ')') && (*it != '+') && (*it != '-') && (*it != '*') && (*it != '/')){
			qu.push(*it);
			//postfix += *it;
		}

		//else {
		//	postfix += *it;
		//}
	}

for(auto it = input.begin(); it != input.end(); ++it){
		if(*it == '(' || *it == ')' || *it == '+' || *it == '-' || *it == '*' || *it == '/'){
			qu.push(*it);
			//postfix += *it;
		}

	}

	int i=0;
	//not empty then insert position of queue in string 
	//then pop
	while (!qu.empty())
    {
    postfix.insert(i,1,qu.front());
    i++;
    
    qu.pop();
    }
//show postfix version
return postfix;



	
}

 
