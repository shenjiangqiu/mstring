#pragma once
///
/// @file    String.cc
/// @author  shenjiangqiu(ivy22233qiu@live.com)
/// @date    2017-02-04 10:08:59
///
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
///
/// @file    String.cc
/// @author  shenjiangqiu(ivy22233qiu@live.com)
/// @date    2017-02-04 10:08:59
///
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class mstring
{
private:
	char * _buf;
	int _size;
	int _space;
public:
	mstring();
	mstring(const char *);
	mstring(const mstring &);
	~mstring();
	mstring & operator =(const mstring& cp);
	friend mstring operator +(const mstring &a, const mstring &b);
	friend mstring operator +(const mstring &a, const char *b);
	friend mstring operator +(const char *, const mstring &b);
	friend std::ostream& operator <<(std::ostream &ost, const mstring &a);
	friend std::istream& operator >> (std::istream &ist, mstring &a);
};