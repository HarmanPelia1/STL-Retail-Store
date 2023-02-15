#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
 //come back to fix the punctuation issue


    set<string> keywords;
  	string lower_word = convToLower(rawWords);
  	string new_word = "";
    int pos = -1;
	while(1) { //pos != std::string::npos) {
        for (int i = 0; i < lower_word.size(); i++) {
            if ((ispunct(lower_word[i]) && lower_word[i] != '-')  || isspace(lower_word[i])) {
                pos = i;
                break; 
            }
        }
      if (pos != -1) {
        //find a delimiter, use substr to get the word and add it to set
        string word = lower_word.substr(0, pos);
        if(word.size() >=2){
          
        keywords.insert(word);
        // update lower_word to the next possible word
        }
        lower_word = lower_word.substr(pos+1);
      }
      else {
        break;
      }
      pos = -1;
    }
    if (lower_word.size() >= 2) keywords.insert(lower_word);
return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
