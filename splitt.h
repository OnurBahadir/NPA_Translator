#ifndef SPLITT_H
#define SPLITT_H


#include <vector>
#include <string>


std::vector<std::string> splitt(const std::string &s,char x){
	std::string el="";
	std::vector<std::string> data;
	for(int i=0;i<s.size();i++){
		if( s[i]==x ){
			data.emplace_back(el);
			el="";
		}
		else{
			el+=s[i];
		}
		if(i==(s.size()-1) ){
			if(s[i]!=x){
				data.emplace_back(el);
			}
		}
	}
	return data;
}



#endif