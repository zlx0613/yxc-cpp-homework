// MyString.cpp
#define _CRT_SECURE_NO_DEPRECATE
#include "String.h"
#include <iostream>
#include "MyString.h"
using namespace std;

// 【知识点：组合关联】在构造函数中 new，在析构函数中 delete。
// 强制同步了 MyString 对象与动态数组 ptrCharArray 的生命周期，确保“同生共死”。
MyString::MyString(const char s[]) {
	len = strlen(s);
	ptrCharArray = new char[len + 1];
	strncpy(ptrCharArray, s, len + 1);
	ptrCharArray[len] = '\0';
}

MyString::MyString(const MyString &oldMyString) {
	len = oldMyString.getLen();
	ptrCharArray = new char[len + 1];
	strncpy(ptrCharArray, oldMyString.getString(), len + 1);
}

MyString::~MyString() {
	cout << "删除" << ptrCharArray << "字符串" << endl;
	delete ptrCharArray; // 对象的善后职责：释放底层的动态内存
}

void MyString::print() const {
	cout << ptrCharArray << endl;
}

int MyString::getLen() const {
	return len;
}

const char* MyString::getString() const {
	return ptrCharArray;
}

