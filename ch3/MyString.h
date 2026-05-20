// MyString .h
class MyString {
public:
	MyString(const char s[]);
	MyString(const MyString &oldMyString);
	~MyString();
	void print() const;
	int getLen() const;
	const char* getString() const;
private:
	char *ptrCharArray = nullptr;
	int len;
};
