#include <algorithm>
#include <cctype>
#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <stack>
#include <random>

using namespace std;


string delimiters = " ',./\|:;-)(&?!@#%^+=_*$#\"";
stack<pair<string, string>> MyStack;
vector<pair<int,double>> AllStat;
vector<double> AllTime;
int errors= 0;
int noErrors = 0;
int noSolution = 0;
long long timeOfPrint = 0;
ofstream ans;


void taskA(string inputFile, string outputFile)
{
	vector<pair<int, string>> MyVector;
	ifstream in;
	in.open(inputFile);
	if(!in.is_open())
	{
		errors++;
		return;
	}
	string str;
	(getline(in, str));
	if(str.empty())
	{
		noSolution++;
		return;
	}
	do
	{
		transform(str.begin(), str.end(), str.begin(), tolower);
		int begin = 0; int end = 0;
		while (begin != str.size() - 1)
		{
			begin = str.find_first_not_of(delimiters, end);
			end = str.find_first_of(delimiters, begin);
			if (begin == -1)
			{
				break;
			}
			if (end == -1)
			{
				end = str.size() - 1;
			}
			string substr = str.substr(begin, end - begin);
			bool flag = false;
			for (int i = 0; i < MyVector.size(); i++)
			{
				if (MyVector[i].second == substr)
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
	sort(MyVector.begin(), MyVector.end(), [&](pair<int, string> dict1, pair<int, string> &dict2)
	{
		return (dict1.first > dict2.first);
	});
	int max = MyVector[0].first;
	ofstream out;
	out.open(outputFile);
	int i = 0;
	while (MyVector[i].first == max)
	{
		out << MyVector[i].second << "\n";
		i++;
		if(i >= MyVector.size())
		{
			break;
		}
	}
	out << endl;
	out << "Встречались " << max << " раз" << endl;

	pair<string, string> data;
	data.first = inputFile;
	data.second = outputFile;
	out.close();

	long long begin = clock();
	ans << inputFile << " ---> " << outputFile << endl;
	i = 0;
	while (MyVector[i].first == max)
	{
		out << MyVector[i].second << "\n";
		ans << MyVector[i].second << ", ";
		i++;
		if (i >= MyVector.size())
		{
			break;
		}
	}
	ans << endl;
	ans << "Встречались " << max << " раз" << endl;
	long long end = clock();
	timeOfPrint += end - begin;
	noErrors++;

}


void dataGeneretion(int numberOfSets)
{
	srand(time(NULL));
	for(int i = 0; i < numberOfSets; i++)
	{
		ofstream out;
		string nameIN = "input_" + to_string(i) + ".txt";
		string nameOUT = "output_" + to_string(i) + ".txt";
		out.open(nameIN);
		for (int j = 0; j < rand() % 1000; j++)
		{
			for (int k = 0; k < 5 + rand()% 6; k++)
			{
				string word;
				for (int m = 0; m < 1 + rand() % 5; m++)
				{
					word += char('a' + rand() % ('z' - 'a'));
				}
				out << word << " ";
			}
			out << endl;
		}
		pair<string, string> data;
		data.first = nameIN;
		data.second = nameOUT;
		MyStack.push(data);

	}
}

void MyThreadB()
{
	int num = 0;
	long long start = clock();
	while (!MyStack.empty())
	{
		num++;
		pair<string, string> data;
		data = MyStack.top(); MyStack.pop();
		string inputFile = data.first;
		string outputFile = data.second;
		taskA(inputFile, outputFile);
	}
	long long end = clock();
	double time = (end - start);
	pair<int, double> stat;
	stat.first = num;
	stat.second = time;
	AllStat.push_back(stat);
	AllTime.push_back(time);
}

int main()
{
	setlocale(LC_ALL, "rus");
	ans.open("Answer.txt");
	int threadCount;
	int taskCount;
	cout << "Введите количество потоков:" << endl;
	cin >> threadCount;
	cout << "Введите количество задач:" << endl;
	cin >> taskCount;
	system("cls");
	dataGeneretion(taskCount);
	for(int i = 0; i < threadCount; i++)
	{
		thread MyThread(MyThreadB);
		MyThread.detach();
	}
	while (true)
	{
		if (errors + noErrors + noSolution == taskCount)
			break;
	}
	cout << "Завершено задач:\t "<< noErrors << endl;
	cout << "Завершено c ошибками:\t " << errors << endl;
	cout << "Нет решения:\t\t " << noSolution << endl;
	sort(AllTime.begin(),AllTime.end(), [](double x, double y)
	{
		return x > y;
	});
	cout << endl;
	for(int i = 0; i < AllStat.size(); i++)
	{
		cout << i + 1 << " поток выполнил " << AllStat[AllStat.size()-i - 1].first << " задач за " << AllStat[AllStat.size() - i - 1].second << " ms;" << endl;;
	}
	cout << endl;
	cout << AllTime[0] << " ms - самое медленное выполнение;" << endl;
	cout << AllTime[AllTime.size() - 1] << " ms - самое быстрое выполнение;" << endl;
	cout << endl;
	cout << "Для записи в файл Answer.txt всех ответов, потребовалось "<< timeOfPrint <<" ms." << endl;
	cout << endl;
	ans.close();
	system("pause");
	return 0;
}