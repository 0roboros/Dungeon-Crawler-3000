#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
int main(){
	std::string s = "testlayout.txt";
	ifstream inp(s.c_str());
	inp >> noskipws;
	char c;
	for (int k = 0; k < 3; k++){
		for (int l = 0; l < 4; l++){
			inp >> c;
			if ((c == '\n') || (c == '\r')){
			}
			else
			cout << c;
		}
		cout << endl;
	}



}
