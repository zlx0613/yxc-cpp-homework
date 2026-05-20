#include "SmartCard.h"
#include <iostream>
using namespace std;

// 知识点20：全局对象 (存储在全局数据区，main函数执行前就分配内存并调用构造函数)
SmartCard g_card(1000, "管理员", 500.0);

void testLocalAndHeap() {
	cout << "\n--- 进入 testLocalAndHeap 函数 ---" << endl;

	// 知识点21：局部对象 (存储在栈区，进入作用域创建，离开时自动调析构函数)
	SmartCard local_card(1001, "张三", 100.0);

	// 知识点22：对象的赋值与初始化 (像使用基本变量一样使用对象，触发拷贝构造)
	SmartCard copy_card = local_card;

	// 知识点23：堆对象与指针 (由程序员通过new手动分配，存储在堆区，必须用指针接收)
	SmartCard* heap_card = new SmartCard(1002, "李四", 200.0);

	// 知识点24：使用 -> 运算符，通过指针调用对象的成员函数
	heap_card->consume(30.0);
	heap_card->print();

	// 知识点25：动态内存管理 (必须手动 delete 释放堆内存，否则导致内存泄漏！触发析构)
	delete heap_card;

	cout << "--- 准备退出 testLocalAndHeap 函数 ---" << endl;
	// 退出时，栈区的 local_card 和 copy_card 被系统自动析构回收
}

int main() {
	cout << "系统启动，当前总卡数：" << SmartCard::getTotalCards() << endl; // 访问静态成员

	testLocalAndHeap(); // 调用测试函数，观察局部对象和堆对象的生死

	cout << "\n--- 演示对象数组 ---" << endl;
	// 知识点26：对象数组 (在栈区连续分配内存，并连续调用10次默认构造函数)
	SmartCard cardArray[10];
	
	cout << "\n系统准备关闭，当前总卡数：" << SmartCard::getTotalCards() << endl;
	return 0;
	// main结束时，自动析构 cardArray 数组和全局对象 g_card
}