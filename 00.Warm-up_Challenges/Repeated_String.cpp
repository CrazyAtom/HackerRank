#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n)
{
	if (s.length() == 1 && s[0] == 'a')
	{
		return n;
	}

	long count = 0;
	const int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == 'a')
			count++;
	}
	cout << "count : " << count << endl;
	if (!count)
		return 0;

	const long repeated = n / len;
	count *= repeated;
	cout << "repeated : " << repeated << endl;
	cout << "count : " << count << endl;

	const long rem = n % len;
	for (int i = 0; i < rem; ++i)
	{
		if (s[i] == 'a')
			count++;
	}
	cout << "rem : " << rem << endl;
	cout << "count : " << count << endl;

	return count;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string n_temp;
	getline(cin, n_temp);

	long n = stol(ltrim(rtrim(n_temp)));

	long result = repeatedString(s, n);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

	return s;
}
