#include <algorithm>
#include <cctype>
#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

string delimiters = " ',./\|:;-)(&?!@#%^+=_*$#\"";
double timeOfWork = 0;


void taskA(string inputFile, string outputFile)
{
	long long start = clock();
	vector<pair<int, string>> MyVector;
	ifstream in;
	in.open(inputFile);
	if (!in.is_open())
	{
		ofstream out;
		out.open(outputFile);
		out << "Входной файл не существует!" << endl;
		out.close();
		return;
	}
	string str;
	getline(in, str);
	if (str == "")
	{
		ofstream out;
		out.open(outputFile);
		out << "Входной файл пуст!" << endl;
		out.close();
		return;
	}
	do
	{
		transform(str.begin(), str.end(), str.begin(), tolower);
		int begin = 0; int end = 0;
		while(begin!=str.size()-1)
		{
			begin = str.find_first_not_of(delimiters, end);
			end = str.find_first_of(delimiters, begin);
			if(begin == -1)
			{
				break;
			}
			if(end == -1)
			{
				end = str.size() - 1;
			}
			string substr = str.substr(begin, end - begin);
			bool flag = false;
			for(int i = 0; i < MyVector.size(); i++)
			{
				if(MyVector[i].second == substr)
				{
					MyVector[i].first++;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				pair<int, string> add;
				add.second = substr;
				add.first = 1;
				MyVector.push_back(add);
			}
			begin = end;
		}
	}while (getline(in, str));

	in.close();
	sort(MyVector.begin(), MyVector.end(),[&](pair<int,string> dict1, pair<int, string> &dict2)
	{
		return (dict1.first > dict2.first);
	});

	int max = MyVector[0].first;

	ofstream out;
	out.open(outputFile);
	int i = 0;
	while(MyVector[i].first == max)
	{
		out << MyVector[i].second << endl;
		i++;
	}
	out << "Встречались " << max << " раз" << endl;
	out.close();
	long long end = clock();
	timeOfWork = (end - start) / 1000.0;
}


int main()
{
	setlocale(LC_ALL, "rus");
	thread MyThread(taskA, "input.txt", "output.txt");
	MyThread.join();
	cout << "Время работы программы " << timeOfWork << " ms" << endl;
	system("pause");
	return 0;
}