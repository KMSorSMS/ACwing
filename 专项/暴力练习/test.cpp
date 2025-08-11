#include <string>
#include <iostream>
using namespace std;

int main(){
	std::string s1 = "C++";
    std::string s2 = "Programming";
    std::string s3 = "Hello, World!";
    std::string s4 = "I love coding.";
	s1.insert(1,"*.");
	s2.insert(s2.size(),"*.");
    s3 = s3.substr(3,3);
	cout << "s1: " << s1 << "\n";
	cout << "s2: " << s2 << "\n";
	cout << "s3: " << s3 << "\n";
}