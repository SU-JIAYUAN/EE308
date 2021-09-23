#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

const string KEYWORDS[] = { "auto","break","case","char","const","continue","default"
,"do","double","else","enum","extern","float","for","goto","if"
,"int","long","register","return","short","signed","sizeof","static"
,"struct","switch","typedef","union","unsigned","void","volatile","while" };

const int keywords_list_num = 32;

int keywords_count = 0;
int switch_count = 0;
int case_count = 0;
int total_selection_count = 0;
int if_else_count = 0;
int if_elseif_else_count = 0;
string path;
int level;

void countKeywords(fstream& fName);
void countSwitch();
void countSelectionTotal();
void countIfElseNum();
void countIfElseifElseNum();
void userInterfaceHiddenCode(string path, int level);

vector<string> keywordsAndBracesShown;
vector<string> keywordsShown;
vector<string> words;
vector<int>switchPositions;


int main(){
	cout << "Please input the path of the file:" << endl;
	cin >> path;
	cout << "Please input the completion level:" << endl;
	cin >> level;
	userInterfaceHiddenCode(path, level);

	return 0;
}


void userInterfaceHiddenCode(string path,int level) {
	fstream File;
	File.open(path.c_str());

	if (File.fail()) 
	{
		cout << "The file was not successfully opened"
			<< "\n Please check that the file currently exists."
			<< endl;
	}
	if (level > 0 && level <= 4) {
		countKeywords(File);
		if (level > 1 && level <= 4) {
			countSwitch();
			if (level > 2 && level <= 4) {
				countSelectionTotal();
				countIfElseNum();
				if (level > 3 && level <= 4) {
					countIfElseifElseNum();
				}
			}
		}
	}
}	



void countKeywords(fstream& fName){
	string str;
	string semicolon = ";";
	string colon = ":";
	fName.seekg(0, ios::beg);
	while (fName >> str)
	{
		words.push_back(str);
		for (int i = 0; i < keywords_list_num; i++) {
			if (str.compare(KEYWORDS[i]) == 0 ||
				(str.compare(KEYWORDS[i]) != 0 &&
					str.substr(0, KEYWORDS[i].length()).compare(KEYWORDS[i]) == 0 &&
					(ispunct(str[KEYWORDS[i].length()]))
					)
				) {
				keywords_count++;
				keywordsShown.push_back(str);
				break;
			}
		}
	}
	cout << "total num: " << keywords_count << endl;
}



void countSwitch() {
	string str;
	string target_switch = "switch";
	string target_case = "case";

	for(int i = 0; i < keywords_count; i++){
		// cout << keywordsShown[i] << endl;
		if (keywordsShown[i].compare(target_switch) == 0 ||
			(keywordsShown[i].compare(target_switch) != 0 &&
				keywordsShown[i].substr(0, target_switch.length()).compare(target_switch) == 0 &&
				(ispunct(keywordsShown[i][target_switch.length()]))
				)
			) {
			switchPositions.push_back(i);
		}
	}
	switch_count = switchPositions.size();
	cout << "switch num: " << switch_count << endl;
	cout << "case num: ";
	switchPositions.push_back(keywords_count);
	switch_count = switchPositions.size();
	
	for (int j = 0; j < switch_count - 1; j++) {
		for (int k = switchPositions[j]; k < switchPositions[j + 1]; k++) {
			
			if (keywordsShown[k].compare(target_case) == 0 ||
				(keywordsShown[k].compare(target_case) != 0 &&
					keywordsShown[k].substr(0, target_case.length()).compare(target_case) == 0 &&
					(ispunct(keywordsShown[k][target_case.length()]))
					)
				) {
				case_count++;
			}
		}
		cout << case_count << " ";
		case_count = 0;
	}
	cout << endl;
}



void countSelectionTotal() {
	for (int i = 0; i < keywords_count; i++) {
		if (keywordsShown[i].compare("else{") == 0 ||keywordsShown[i].compare("else{}") == 0 ||
			(keywordsShown[i].compare("else") == 0 && keywordsShown[i - 1].compare("if") != 0)) {
			total_selection_count++;
		}
	}
}



void countIfElseNum() {
	string keywordsAndBraces[] = { "auto","break","case","char","const","continue","default"
	,"do","double","else","enum","extern","float","for","goto","if"
	,"int","long","register","return","short","signed","sizeof","static"
	,"struct","switch","typedef","union","unsigned","void","volatile","while","{","}" };
	for (int i = 0; i < words.size();i++) {
		for (int j = 0; j < keywords_list_num + 2; j++) {
			if (words[i].compare(keywordsAndBraces[j]) == 0 || 
				(words[i] != "{" && words[i] != "}" && words[i].compare(keywordsAndBraces[j]) != 0 &&
				words[i].substr(0, keywordsAndBraces[j].length()).compare(keywordsAndBraces[j]) == 0 &&
				(ispunct(words[i][keywordsAndBraces[j].length()])))) {

				keywordsAndBracesShown.push_back(words[i]);
			}
		}
	}
	for (int i = 0; i < keywordsAndBracesShown.size(); i++) {
		if (keywordsAndBracesShown[i].compare("else") == 0 && keywordsAndBracesShown[i + 1].substr(0, 2).compare("if") == 0) {
			keywordsAndBracesShown[i] = 'A';
			keywordsAndBracesShown[i + 1] = 'A';
		}
	}
	for (int i = 0; i < keywordsAndBracesShown.size(); i++) {
		if (keywordsAndBracesShown[i].substr(0, 2).compare("if") == 0 && keywordsAndBracesShown[i + 1].substr(0, 4).compare("else") == 0) {
			if_else_count++;
		}
	}
	cout << "if-else num: " << if_else_count << endl;
}
	



void countIfElseifElseNum() {
	if_elseif_else_count = total_selection_count - if_else_count;
	cout << "if-elseif-else num: " << if_elseif_else_count << endl;
}
	

