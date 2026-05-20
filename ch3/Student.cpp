#define _CRT_SECURE_NO_DEPRECATE

#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

int Student::noOfStudents = 0;
Student *Student::pFirst = NULL; // 静态关联属性的全局初始化

int Student::number(void) {
	return noOfStudents;
}

// 【知识点：静态成员函数与遍历】静态函数直接通过 pFirst 遍历整个网络
Student* Student::findname(const char *pName) {
	for (Student *pS = pFirst; pS; pS = pS->pNext)
		if (strcmp(pS->name.getString(), pName) == 0)
			return pS;
	return NULL;
}

// 【知识点：组合关联的生命周期同步】
// 构造函数中使用冒号 (:) 语法，调用成员对象 name 的构造函数，同步对象的出生。
Student::Student(const char *pName) :
		name(pName) {
	cout << "插入：" << this->name.getString() << endl;
	
	// 【知识点：头插法建表】
	// 对象一诞生，就主动承担起“将自己接入网络”的职责，不需要外部管理者干预。
	pNext = pFirst;          //每新建一个结点(对象),就将其挂在链首
	pFirst = this;
}

// 【知识点：对象的善后职责（维护外部关联）】
Student::~Student() {
	cout << "删除：" << this->name.getString() << endl;
	
	// 对象在被销毁前，主动找到自己在网络中的位置，并将前后节点重新连接。
	if (pFirst == this) {       //如果要删除链首结点,则只要链首指针指向下一个
		pFirst = pNext;
		return;
	}
	for (Student *pS = pFirst; pS; pS = pS->pNext) {
		if (pS->pNext == this) {  //找到时,pS指向当前结点的结点
			pS->pNext = pNext;    //pNext即this->pNext，断表重连，对象的本能
			return;
		}
	}
}
