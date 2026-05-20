/*
 * Student.h
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "MyString.h"

class Student {
public:
	static int number(void);
	static Student* findname(const char *pName);
	Student(const char *pName);
	~Student();
private:
	// 【知识点：组合关联】
	// 使用成员对象 name 表示组合关联。描述“整体”与“部分”的构成关系，且两者生命周期绝对相同。
	MyString name;	//存储组合关联name中的连接

	// 【知识点：一般关联与自关联】
	// 两个 Student 对象生命周期不同步，因此使用“成员指针”表示一般关联中的连接。
	// 这里类 Student 关联到它自己，被称为自关联。
	Student *pNext;	//指向链表中的下一个Student对象

	// 【知识点：自关联】
	// pFirst 属于类，而非单个对象。类的所有对象共享这一个指针，它永远指向链表中的第一个对象。
	static Student *pFirst;	//指向链表中的第一个Student对象

	static int noOfStudents;	//存储学生人数
};

#endif /* STUDENT_H_ */
