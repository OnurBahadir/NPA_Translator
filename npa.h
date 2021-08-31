#ifndef NPA_H
#define NPA_H

#include <string>
#include <algorithm>
#include <sstream>
#include <map>

#include "splitt.h"

namespace npa {
	
   	const std::map< std::string ,std::string> alphabet{
        	{"a","Alpha"},
            {"b","Bravo"},
            {"c","Charlie"},
            {"d","Delta"},
            {"e","Echo"},
            {"f","Foxtrot"},
        	{"g","Golf"},
            {"h","Hotel"},
            {"i","India"},
            {"j","Juliet"},
            {"k","Kilo"},
            {"l","Lima"},
        	{"m","Mike"},
            {"n","November"},
            {"o","Oscar"},
            {"p","Papa"},
            {"q","Quebec"},
            {"r","Romeo"},
        	{"s","Sierra"},
            {"t","Tango"},
            {"u","Uniform"},
            {"v","Victor"},
            {"w","Whiskey"},
            {"x","X-ray"},
       	 	{"y","Yankee"},
            {"0","Zero"},
            {"1","One"},
            {"2","Two"},
            {"3","Three"},
            {"4","Four"},
            {"5","Five"},
        	{"6","Six"},
            {"7","Seven"},
            {"8","Eight"},
            {"9","Nine"},
            {".","Stop"},
            {"-","Dash"},
            {" ","[Space]"},
            {"&","Ampersand"}
    	};

	std::string Tolower(const std::string &st) {
		std::string s(st);
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
		return s;
	}


	
	std::string text2npa( const std::string& s ) {
		std::string temp= Tolower(s);
        std::string npa="";
		for ( auto &i : temp ) { 
            std::stringstream ss;
            ss<<i;
            auto search = alphabet.find(ss.str());
            if ( search != alphabet.end() ) {
                npa+=search->second;
                npa+=" ";
            } 
        }
		return npa;
	}

    std::string npa2text( const std::string &npa){
        std::vector<std::string> words=splitt(npa,' ');
        std::string sentence="";
        for(const auto &x : words){
            auto a=Tolower(x);
            if(a=="[space]"){
                sentence+=" ";
            }
            else if(a=="stop"){
                sentence+=".";
            }
            else if(a=="dash"){
                sentence+="-";
            }
            else if(a=="ampersand"){
                sentence+="&";
            }
            else{
                sentence+=a[0];
            }
        }
        return sentence;
    }   
}


#endif
