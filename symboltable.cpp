#include <iostream>
#include <map>
using namespace std;
struct SymbolTable{
  map<string,double>symbol;
  
  void set(string name,double value){
    symbol[name]=value;
  }
  double get (string name){
    for(map<string,double>:: iterator it=symbol.begin();it!=symbol.end();++it){
     if (name == (*it).first)
		{
			return symbol[name];
			exit(0);
	}}
	 KeywordError("invalid keyword",name);
	return 0;
}
 bool is_defined(string name){
    for(map<string,double>:: iterator iter=symbol.begin();iter!=symbol.end();++iter){
    if (name == (*iter).first)
		{
	  return true;		
			exit(0);
	}}
    return false;
}
};
