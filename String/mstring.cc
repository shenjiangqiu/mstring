#include<string.h>
#include"mstring.h"

mstring::mstring() :_buf(new char[10]), _size(0), _space(10) {}

mstring::mstring(const char * buf)
	: _buf(new char[strlen(buf) + 1])
	, _size(strlen(buf))
	, _space(strlen(buf) + 1)
{
	strcpy(_buf, buf);

}

mstring::mstring(const mstring & cp) :
	_buf(new char[cp._space])
	, _size(cp._size)
	, _space(cp._space)
{
	strcpy(_buf, cp._buf);
}

mstring::~mstring()
{
	if (_space != 0)
		delete[] _buf;
}

mstring& mstring::operator=(const mstring& cp)
{
	if (this != &cp)
	{
		if (this->_space != 0)
			delete[] _buf;
		this->_size = cp._size;
		this->_space = cp._space;
		this->_buf = new char[this->_space];
		strcpy(_buf, cp._buf);
	}
	return *this;
}

mstring operator +(const mstring& a, const mstring& b)
{
	mstring tmp;
	delete[] tmp._buf;
	tmp._buf = new char[a._size + b._size + 1];
	tmp._size = a._size + b._size;
	tmp._space = a._size + b._size + 1;
	strcpy(tmp._buf, a._buf);
	strcat(tmp._buf, b._buf);
	return tmp;
}

mstring operator +(const mstring &a, const char *b)
{
	mstring tmp;
	delete[] tmp._buf;
	tmp._size = a._size + strlen(b);
	tmp._space = tmp._size + 1;
	tmp._buf = new char[tmp._space];
	strcpy(tmp._buf, a._buf);
	strcat(tmp._buf, b);
	return tmp;
}
mstring operator +(const char *b, const mstring &a)
{
	mstring tmp;
	delete[] tmp._buf;
	tmp._size = a._size + strlen(b);
	tmp._space = tmp._size + 1;
	tmp._buf = new char[tmp._space];
	strcpy(tmp._buf, b);
	strcat(tmp._buf, a._buf);
	return tmp;


}
std::ostream& operator <<(std::ostream &ost, const mstring &a)
{
	ost << a._buf;
	return ost;
}
std::istream& operator >> (std::istream &ist, mstring &a)
{
	char buf[100];
	ist >> buf;
	mstring tmp(buf);
	a = tmp;
	return ist;
}
