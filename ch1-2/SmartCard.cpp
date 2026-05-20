#define  _CRT_SECURE_NO_WARNINGS

#include "SmartCard.h"
#include <iostream>
#include <cstring> // 用于 strncpy 和 memcpy
using namespace std;

// 知识点14：静态成员变量必须在类外部（实现文件中）进行全局初始化
int SmartCard::totalCards = 0;

// 知识点15：作用域运算符(::)，指明该函数属于 SmartCard 类的边界之内
SmartCard::SmartCard() {
	id = 0;
	balance = 0.0;
	strncpy(ownerName, "未命名", sizeof(ownerName)-1);
	ownerName[sizeof(ownerName)-1] = '\0';
	//strncpy_s(ownerName, "未命名", sizeof(ownerName)-1);
	totalCards++; // 每发一张卡，共享的总数+1
	cout << "调用默认构造函数" << endl;
}

SmartCard::SmartCard(int cardId, const char* owner, float initialBalance) {
	id = cardId;
	balance = initialBalance;
	// 知识点16：安全的字符数组赋值，防溢出并确保 '\0' 结尾 (教材经典写法)
	strncpy(ownerName, owner, sizeof(ownerName)-1);
	ownerName[sizeof(ownerName)-1] = '\0';
	//strncpy_s(ownerName, owner, sizeof(ownerName)-1);
	totalCards++; // 每发一张卡，共享的总数+1
	cout << "带参构造：发卡号 " << id << "，持卡人：" << ownerName << endl;
}

SmartCard::SmartCard(const SmartCard& oldCard) {
	// 知识点17：隐含的 this 指针。编译器自动传递，指向当前正在创建的新对象
	this->id = oldCard.id;
	this->balance = oldCard.balance;
	// 知识点18：使用 memcpy 进行内存数据的按字节拷贝 (教材中的深浅拷贝基础)
	memcpy(this->ownerName, oldCard.ownerName, sizeof(ownerName));

	totalCards++;
	cout << "拷贝构造：克隆卡号 " << id << endl;
}

SmartCard::~SmartCard() {
	totalCards--;
	cout << "析构函数：注销卡号 " << id << "，持卡人：" << ownerName << "，剩余总卡数：" << totalCards << endl;
}

bool SmartCard::consume(float amount) {
	// 知识点19：封装的计算价值——屏蔽内部逻辑，保护 balance 不被非法扣成负数
	if (balance >= amount) {
		balance -= amount;
		return true;
	}
	return false;
}

void SmartCard::recharge(float amount) {
	if (amount > 0) balance += amount;
}

int SmartCard::getTotalCards() {
	return totalCards;
}

void SmartCard::print() const {
	cout << "卡号: " << id << ", 持卡人: " << ownerName << ", 余额: " << balance << endl;
}