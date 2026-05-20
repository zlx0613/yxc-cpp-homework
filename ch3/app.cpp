#include <iostream>
#include "Student.h"
using namespace std;

int main() {
	Student s1("Randy");

	// 【知识点：堆对象与无名对象】
	// 虽然没有指针变量接收它，但由于它的构造函数主动将自己挂载到了 pFirst 静态链表上，
	// 所以它绝不会造成内存泄漏（即“丢失”），而是被整个类的链表网络安全地管理了起来。
	new Student("Jenny");
	Student s2("Kinsey");
	cout << "查找Jenny：";
	Student *pS1 = Student::findname("Jenny"); // 返回指向堆中无名对象的指针
	if (pS1)
		cout << "ok." << endl;
	else
		cout << "no find." << endl;

	// 【知识点：触发对象自我清理连接】
	// delete 操作会触发该对象的析构函数。在析构函数中，它会自动将自己从 pFirst 链表中摘除。
	delete pS1;

	cout << "查找Jenny：";
	Student *pS2 = Student::findname("Jenny");
	if (pS2)
		cout << "ok." << endl;
	else
		cout << "no find." << endl;
	
	return 0;
}
