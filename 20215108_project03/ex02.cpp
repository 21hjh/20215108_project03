#include <iostream>
#include <cstring> // strcpy, strcmp

using namespace std;

class String
{
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String& str)const
	{
		return strcmp(_chars, str._chars) == 0;
	}

	bool operator>(const String& str)const
	{
		return strcmp(_chars, str._chars) > 0;
	}

	bool operator<=(const String& str)const
	{
		//<=ÀÇ ¹Ý´ë? -> >
		return !(*this > str);
	}
	bool operator<(const String& str)const
	{
		return strcmp(_chars, str._chars) < 0;
	}
	bool operator>=(const String& str)const
	{
		return !(*this < str);
	}
};

int main()
{
	String str0{ "abc" };
	String str1{ "cde" };

	if (str0 == str1)//str0.opreator==(str1)
		cout << "equal" << endl;

	if (str0 > str1)//str0.opreator>(str1)
		cout << "str0>str1" << endl;

	if (str0 <= str1)//str0.opreator<=(str1)
		cout << "str0<=str1" << endl;

	if (str0 < str1)//str0.opreator<(str1)
		cout << "str0<str1" << endl;

	if (str0 >= str1)//str0.opreator>=(str1)
		cout << "str0>=str1" << endl;
}