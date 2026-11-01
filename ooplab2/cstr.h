#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>


class Cstr {
	char* a;
	static char* genrand(int len) {
		if (len > 20) len = 20;
		if (len < 0) len = 0;
		char* str = new char[len + 1];
		const char charset[] = "abcdefghijklmnopqrstuvwxyz";
		int charsetSize = sizeof(charset);

		for (int i = 0; i < len; ++i) {
			str[i] = charset[rand() % charsetSize];
		}
		str[len] = '\0';
		return str;

	}
public:
	Cstr() {
		int randLen = rand() % 20 + 1;
		a = genrand(randLen);
	}
	Cstr(const char* str) {
		if (str == nullptr) {
			a = new char[1];
			a[0] = '\0';
			return;
		}
		size_t len = strlen(str);
		a = new char[len + 1];
		strcpy(a, str);
	}
	Cstr(int len) {
		a = genrand(len);
	}
	Cstr(const Cstr& b) {
		size_t len = strlen(b.a);
		a = new char[len + 1];
		strcpy(a, b.a);
	}
	~Cstr() {
		delete[] a;
	}
	Cstr& operator=(const Cstr& b) {
		if (this == &b) {
			return *this; 
		}
		delete[] a;
		size_t len = strlen(b.a);
		a = new char[len + 1];
		strcpy(a, b.a);
		return *this;
	}
	Cstr& operator=(const char* str) {
		if (str == nullptr) {
			a = new char[1];
			a[0] = '\0';
			return *this;
		}
		delete[] a;
		size_t len = strlen(str);
		a = new char[len + 1];
		strcpy(a, str);
		return *this;
	}
	bool operator>(const Cstr& b) const {
		return strcmp(a, b.a) > 0;
	}
	bool operator<(const Cstr& b) const {
		return strcmp(a, b.a) < 0;
	}
	Cstr& operator+=(const Cstr& b) {
		size_t len1 = strlen(a);
		size_t len2 = strlen(b.a);
		size_t newlen = len1 + len2;
		char* a2 = new char[newlen + 1];
		strcpy(a2, a);
		strcat(a2, b.a);
		delete[] a;
		a = a2;
		return *this;
	}
	Cstr operator+(const Cstr& b) const {
		Cstr a2(*this);
		a2 += b;
		return a2;
	}
	char& operator[](int i) {
		if (i < 0 || i >= strlen(a)) { puts("index out of range"); exit(0);}
		return a[i];
	}
	size_t len() const {
		return strlen(a);
	}
	friend std::ostream& operator<<(std::ostream& os, const Cstr& str) {
		os << str.a;
		return os;      
	}
	friend std::istream& operator >>(std::istream& is, Cstr& str) {
		char buf[21];
		gets_s(buf, 21);
		if (is.fail()) {
			buf[0] = '\0';
			is.clear();
		}
		Cstr c(buf);
		str = c;
		return is;
	}

};

