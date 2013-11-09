/*
 * internal class for determineRule.cpp
 * */
#include "preliminary.h"
#include <vector>

class comparerule{
public:
	comparerule(int n):a(n){}
	virtual ~comparerule(){}
	virtual bool evaluate(int) = 0;
protected:
	int a;
};

class mygreater : public comparerule{
public:	
	mygreater(int x) : comparerule(x){}
	~mygreater(){}
	bool evaluate(int);
};

bool mygreater::evaluate(int x){
	return x>a ? true : false;
}

class myequal:public comparerule{
public:
	myequal(int x):comparerule(x){}
	~myequal(){}
	bool evaluate(int);
};

bool myequal::evaluate(int x){
	return x==a ? true : false;
}

class myless:public comparerule{
public:
	myless(int x):comparerule(x){}
	~myless(){}
	bool evaluate(int);
};

bool myless::evaluate(int x){
	return x<a ? true : false;
}

class logicrule : public comparerule{
public:
	logicrule(const string& line):comparerule(0), str(line), key(), pos(0){
		init();
	}
	~logicrule();
	
	bool evaluate(int);
	const char* getkey(){
		return key.c_str();
	}
private:
	string str;
	string key;
	size_t pos;

	vector<comparerule*> rules;
	vector<int> operands;				//1 for AND, 0 for OR
	void init();
	void parseCmpRule();
	void parseLogicOperand();
};

logicrule::~logicrule(){
	rules.clear();
	operands.clear();
}
