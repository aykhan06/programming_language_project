#include <iostream>
using namespace std;

/*
Error classes;
*/
class IllegalCharError{
	string error_name = "IllegalCharError: ";
	public:
		
		IllegalCharError(string details, string char_)
		{
			cout<<error_name+details+" '"+char_+"'"<<endl;
	 }
};


class KeywordError{
	string error_name = "KeywordError: ",identifier="";
	public:
		KeywordError(string details, string identifier){
			this->identifier = identifier;
			
			if(!this->identifier.empty())
			{
			cout<<error_name+details+" '"+this->identifier+"'"<<endl;
			}
			
			else
			{
			cout<<error_name+details<<endl;
			}
			
	}
	
};

class SyntaxError{
	string error_name = "SyntaxError: ",identifier="";
	public:
		SyntaxError(string details, string identifier){
			this->identifier = identifier;
			
			if(!this->identifier.empty())
			{
			cout<<error_name+details+" '"+this->identifier+"'"<<endl;
			}
			
			else
			{
			cout<<error_name+details<<endl;
			}
			
	}
	
};



