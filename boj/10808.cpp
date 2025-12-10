#include <iostream>
using namespace std;

int main()
{
	int list[26] = {};
	string s;
	cin >> s; 
	for(int i=0; i<s.length(); i++) list[s[i]-'a']++;
	for(int i=0; i<26; i++) cout << list[i] << " ";
}
