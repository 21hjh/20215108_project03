#include<iostream>

using namespace std;

class Vector
{
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	Vector(float x, float y, float z, const char* chars)
		:x{ x }, y{ y }, z{ z }, _chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	Vector(Vector& v)
		:Vector(v.x, v.y, v.z, v._chars)
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;
	}
	- Vector()
	{
		delete[] _chars;
	}


	//friend ostream& operator<<(ostream& os, Vector& v) 
	//{
	//	os << v.x << " " << v.y << " " << v.z;
	//	return os;
	//}

	//friend istream& operator >> (istream& is, Vector& v)
	//{
	//	is >> v.x >> v.y >> v.z;
	//	return is;
	//}

	/*float &operator[](int index)
	{
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		return z;
	}*/
	//const
	//const float& operator[](int index)const
	//{
	//	if (index < 1)
	//		return x;
	//	if (index == 1)
	//		return y;
	//	return z;

	//}

	Vector operator = (Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		delete[]_chars;
		_chars = new char[strlen(v._chars) + 1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);

		return *this;
	}

	friend ostream& operator <<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
};
//class String
//{
//private:
//	char* _chars;
//public:
//	String() {}
//	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
//	{
//		strcpy_s(_chars, strlen(chars) + 1, chars);
//	}
//
//	char& operator[](int index)
//	{
//		return _chars[index];
//	}
//};
int main()
{
	//Vector v0{ 1,2,3 }; //2번째 주석 인덱스 연산자
	//cout << v0 << endl;// cout.operator<<(v)->operator<<(cout.v)
	////operator << (cout.v)<<endl; -> endl, cout 멤버함수 cout,endl

	//Vector v1;
	//cin >> v1; //operator >> (cin.v)

	//cout << v1 << endl;
	//cout << v0[-1] << endl;//x
	//cout << v0[0] << endl;//x=1 v0. operator[](int index)
	//cout << v0[1] << endl;//y=2
	//cout << v0[2] << endl;//z=3

	//v0[0] = 100;
	//cout << v0[0] << endl;
	//String str("abc");
	//cout << str[0] << endl;//a
	//cout << str[1] << endl;//b
	//cout << str[2] << endl;//c

	//str[2] = 'd';
	//cout << str[2] << endl;

	//int a = 1;
	//int b = a;//복사
	//int c;
	//c = a;//대입

	Vector v0{ 1,2,3, "abc" };
	Vector v1 = v0;//복사 -> 얉은 복사->깊은복사->복사생성자
	Vector v2;
	v2 = v0;//대입->v2.operator=(v0)

	cout << v0 << endl;
	cout << v1 << endl;
	cout << v2 << endl;

}