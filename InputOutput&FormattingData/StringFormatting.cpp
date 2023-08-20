// Formatting array of characters. Changing each letter in the string to a letter four positions alphabetically to the left of it
#include "StringFormatting.h"
#include <string>

using namespace std;

string* StringFormatting::create(string src)
{
	return new string(src);
}

// Conversion of the character array without accessing its elements by index
string* StringFormatting::format(string* src) {
	int l = (*src).length();
	string* dst = new string();

	for (int i = 0; i < l; i++) {
		char c = (*src).at(i);
		c = (c == 32) ? c : c - 4;
		(*dst) += c;
	}
	return dst;
}

void StringFormatting::cleanup(string* src, string* dst)
{
	delete src, dst;
}
