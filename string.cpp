#include <string>
#include <iostream>

using std::string;

string pigLatinify(string& eng_word){
	const string VOWELS = "aeiou";
	if(VOWELS.find(eng_word[0]) != string::npos){
		return eng_word + "-way";
	}
	else{
		return eng_word.substr(1, eng_word.length()-1) + "-" + eng_word[0] + "ay";
	}
}

int main(int argv, char** argc){
	string name = "name";
	std::cout<<pigLatinify(name)<<std::endl;
	return 0;
}
