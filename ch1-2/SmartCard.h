#ifndef SMARTCARD_H
#define SMARTCARD_H

// 知识点1：类的声明 (class 关键字)
// 知识点2：多文件结构中的头文件 (接口与实现分离)
class SmartCard {
public: // 知识点3：public 接口，允许外部调用的行为

	// 知识点4：默认构造函数 (系统自动调用，多用于对象数组初始化)
	SmartCard();

	// 知识点5：带参数的构造函数 (赋予对象初始化自身数据的职责)
	SmartCard(int cardId, const char* owner, float initialBalance);

	// 知识点6：拷贝构造函数 (使用已有对象创建新对象)
	SmartCard(const SmartCard& oldCard);

	// 知识点7：析构函数 (对象生命周期结束时的善后工作)
	~SmartCard();

	// 知识点8：行为（成员函数），提供与外部交互的渠道
	bool consume(float amount);
	void recharge(float amount);

	// 知识点9：const 成员函数，承诺该函数内部绝不修改对象的属性值
	void print() const;

	// 知识点10：静态成员函数，通过类名直接调用，用于管理全局状态
	static int getTotalCards();

private: // 知识点11：private 访问控制，保护内部数据不被随意篡改
	int id;
	float balance;

	// 知识点12：字符数组属性 (复习C++基础数据结构及字符串处理)
	char ownerName[20];

	// 知识点13：静态成员变量 (类的所有对象共享这一份数据，体现自我管理能力)
	static int totalCards;
};
#endif