/*
IO Lab
John Abendroth
CS 41
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

int main() {

	string sentence;

	cout << "Sentence: ";
	getline(cin, sentence);

	istringstream iss(sentence);
	vector <string> vector((istream_iterator<string>(iss)), istream_iterator<string>());

	for (auto i : vector)
	{
		stringstream test_stream(i);
		float test_num = 0;

		if (test_stream >> test_num)
		{
			test_num *= 2;
			cout << test_num << "\n";
		}
		else
			cout << i << "\n";
	}

	return 0;
}
