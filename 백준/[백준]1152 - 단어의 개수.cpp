#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	string sentence;
	int check = 0;
	getline(cin, sentence, '\n');

	for (int i = 0; i < sentence.size(); i++) {
		if (i != 0 && i != sentence.size() - 1 && sentence[i] == ' ')
		{
			check++;
		}

	}
	if (sentence.size() != 0)
		check++;
	if (sentence.size() == 1 && sentence[0] == ' ')
		check--;
	cout << check << endl;
}