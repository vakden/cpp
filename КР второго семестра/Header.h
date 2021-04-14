#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class clumba
{
public:
	int num;
	string form;
	vector<string> flowers;

	void print(ofstream out)
	{
		out << num << '/' << form;
		for(auto &v : flowers)
		{
			out << '/ '<< v;
		}
		out << endl;
	}
};
