#pragma once
using namespace std;
#include <string>
class StringFormatting {
	public:
		string* create(string src);
		string* format(string* src);
		void cleanup(string* src, string* dst);
};

