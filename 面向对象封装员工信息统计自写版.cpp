#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//ContactInf类定义 负责管理员工的联系方式
class ContactInf {
private:
	string phone;
	string qq;
	string email;
public:
	//默认构造函数
	ContactInf() :phone(""), qq(""), email("") {}
	//带参数的构造函数
	ContactInf(string p, string q, string e) :phone(p), qq(q), email(e) {}
	//用于显示联系信息
	void display()const
	{
		cout << setw(15) << phone
			<< setw(11) << qq
			<< setw(20) << email;
	}
};
//Employee类定义 负责管理单个员工数据
class Employee {
private:
	string name;
	long code;
	double salary;
	string address;
	ContactInf contact;//组合：一个员工有一个联系方式对象
	bool isActive;
public:
	//默认构造函数
	Employee() :name(""), code(0), salary(0.0), address(""),isActive(false) {
	}
	//带参数构造函数
	Employee(string n, long c, double s, string a, const ContactInf& con) :name(n), code(c), salary(s), address(a), contact(con),isActive(true){}
	//析构函数
	~Employee() = default;
	void reset() {
		name = "";
		code = 0;
		salary = 0.0;
		address = "";
		contact = ContactInf();
		isActive = false;
	}
	//Getter方法，用于访问私有成员
	long getCode()const {
		return code;
	}
	bool getIsActive()const {
		return isActive;
	}
	//显示单个员工信息
	void display()const {
		if (!isActive)return;
		cout << setw(15) << name
			<< setw(15) << code
			<< setw(15) << salary
			<< setw(2) << address;
		contact.display();
		cout << endl;
	}
};
//Table类定义 负责动态管理员工对象数组
class Table {
private:
	int arraySize;
	Employee* employeeArray;
	int activeCount;
public:
	//构造函数
	Table(int size) :arraySize(size),activeCount(0){
		employeeArray = new Employee[arraySize];
		cout << "---一创建一个容量为" << arraySize << "的员工信息表---" << endl;
	}
	//析构函数：负责释放动态分配的内存
	~Table() {
		delete[]employeeArray;
		cout << "\n---员工信息表已被销毁，内存已释放---" << endl;
	}
	//禁止拷贝构造和赋值
		Table(const Table&) = delete;
	Table& operator=(const Table&) = delete;
	bool addEmployee(const Employee& emp, int index) {
		if (index >= 0 && index < arraySize&&!employeeArray[index].getIsActive()) {
			employeeArray[index] = emp;
			activeCount++;
			return true;
		}
		return false;
	}
	//查找员工
	int findEmployee(long code) {
		for (int i = 0; i < arraySize; i++) {
			if (employeeArray[i].getCode() == code&&employeeArray[i].getIsActive()) {
				return i;
			}

		}
		return -1;
	}
	//删除员工
	void removeEmployee(long code) {
		int index = findEmployee(code);
		if (index != -1) {
			employeeArray[index].reset();
			activeCount--;
			cout << "---成功将工号为" << code << "的员工离职---" << endl;
		}
		else {
			cout << "---未找到工号为" << code << "的员工---" << endl;
		}
	}
	Employee* getEmployee(int index) {
		if (index >= 0 && index < arraySize) {
			return &employeeArray[index];
		}
		return nullptr;
	}
	//打印所有员工信息
	void printAllEmployees() {
		cout << "当前员工信息表（总人数："<<activeCount<<"):";
		cout << "\n" << setw(15) << "姓名"
			<< setw(15) << "工号"
			<< setw(15) << "工资"
			<< setw(20) << "地址"
			<< setw(15) << "电话"
			<< setw(15) << "QQ"
			<< setw(20) << "邮件" << endl;
		cout << "--------------------------------------------------------" << endl;
		bool hasEmployees = false;
		for (int i = 0; i < arraySize; i++) {
			if (employeeArray[i].getCode() != 0) {
				employeeArray[i].display();
				hasEmployees = true;
			}
		}
		if (!hasEmployees) {
			cout << "---暂无员工信息---" << endl;
		}
		cout << "----------------------------------------------------------" << endl;
	}
};
//主函数
int main() {
	const int TABLE_SIZE = 15;
	Table myTable(TABLE_SIZE);
	//创建员工信息
	cout << "---正在录入新员工---" << endl;
	ContactInf c1("13800138001", "10001", "emp1@company.com");
	Employee e1("张三", 1001, 8500.0, "北京市朝阳区", c1);
	myTable.addEmployee(e1, 0);

	ContactInf c2("13800138002", "10002", "emp2@company.com");
	Employee e2("李四", 1002, 9200.0, "上海市浦东新区", c2);
	myTable.addEmployee(e2, 1);

	ContactInf c3("13800138003", "10003", "emp3@company.com");
	Employee e3("王五", 1003, 7800.0, "广州市天河区", c3);
	myTable.addEmployee(e3, 2);

	ContactInf c4("13800138004", "10004", "emp4@company.com");
	Employee e4("赵六", 1004, 11000.0, "深圳市南山区", c4);
	myTable.addEmployee(e4, 3);

	ContactInf c5("13800138005", "10005", "emp5@company.com");
	Employee e5("孙七", 1005, 9800.0, "杭州市西湖区", c5);
	myTable.addEmployee(e5, 4);

	ContactInf c6("13800138006", "10006", "emp6@company.com");
	Employee e6("周八", 1006, 8900.0, "成都市武侯区", c6);
	myTable.addEmployee(e6, 5);

	ContactInf c7("13800138007", "10007", "emp7@company.com");
	Employee e7("吴九", 1007, 7600.0, "武汉市洪山区", c7);
	myTable.addEmployee(e7, 6);

	ContactInf c8("13800138008", "10008", "emp8@company.com");
	Employee e8("郑十", 1008, 10500.0, "西安市雁塔区", c8);
	myTable.addEmployee(e8, 7);

	ContactInf c9("13800138009", "10009", "emp9@company.com");
	Employee e9("钱十一", 1009, 8200.0, "南京市鼓楼区", c9);
	myTable.addEmployee(e9, 8);

	ContactInf c10("13800138010", "10010", "emp10@company.com");
	Employee e10("陈十二", 1010, 9500.0, "重庆市渝中区", c10);
	myTable.addEmployee(e10, 9);
	//打初始员工信息
	myTable.printAllEmployees();
	//查找并删除指定员工
	long codeToRemove = 1005;
	cout << "---正在查找工号为" << codeToRemove << "的员工---" << endl;
	int foundIndex = myTable.findEmployee(codeToRemove);
	if (foundIndex != -1) {
		cout << "查找成功 该员工信息为：" << endl;
		cout << setw(15) << "姓名"
			<< setw(15) << "工号"
			<< setw(15) << "工资"
			<< setw(20) << "地址"
			<< setw(15) << "电话"
			<< setw(15) << "QQ"
			<< setw(20) << "邮件" << endl;
		cout << "------------------------------------------------------" << endl;
		Employee* emp = myTable.getEmployee(foundIndex);
		if (emp != nullptr) {
			emp->display();
		}
		cout << "----------------------------------------------------------" << endl;
		myTable.removeEmployee(codeToRemove);
	}
	else {
		cout << "---查找失败 未找到该员工" << endl;
	}
	//打印最终员工信息
	myTable.printAllEmployees();
	return 0;
}
