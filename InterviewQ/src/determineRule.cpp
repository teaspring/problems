/*
 * one online question.
 *requirement: 'and' has precedence to 'or'.
 *
 * input: 
 * 45,22
 * rules are in a file
 * n1 : a = 4
 * category 2 : a = 1 or a = 2 or a = 23
 * n3 : a > 100
 * n4 : a > 24 and a < 54
 * n5 : a > 54 and a < 58 or a = 22
 * output: n4,n5
 *
 * Sep14, bug still
 * */
#include "../header/arithrule.h"

int extractNumbersToArray(char *str, int *numbers)
{
    const char *split = ",";
    char *p = strtok (str,split);
    int index = 0;
    while(p!=NULL) {
        numbers[index++] = atoi(p);
        p = strtok(NULL,split);
    }
    return index;
}

void logicrule::init(){
	pos = 0;
	size_t curr = 0;
	while(pos < str.size()){
		if(isspace(str[pos])){
			++pos;
			continue;
		}
		if(key.empty()){				//first parse the key
			curr = pos;
			while(pos < str.size() && str[pos] != ':')
			  ++pos;
			size_t end = pos-1;
			while(isspace(str[end]))
			  --end;
			key = str.substr(curr, end+1-curr);
			++pos;
			continue;
		}
		if((str[pos] == 'a' && rules.size() > operands.size())
			|| str[pos] == 'o'){
			parseLogicOperand();
			continue;
		}

		if(str[pos]=='a' && rules.size()==operands.size()){
			++pos;
			continue;
		}
		if(str[pos] == '>' || str[pos] == '<' || str[pos] == '=')
			parseCmpRule();
	}
}

void logicrule::parseCmpRule(){
	if(pos>=str.size())	return;
	char ch = str[pos++];
	while(pos<str.size() && !isdigit(str[pos]))
	  ++pos;
	size_t cur = pos;
	while(pos<str.size() && isdigit(str[pos]))
	  ++pos;
	int inum = atoi(str.substr(cur, pos-cur).c_str());
	switch (ch){
		case '>':
			rules.push_back(new mygreater(inum));
			break;
		case '<':
			rules.push_back(new myless(inum));
			break;
		case '=':
			rules.push_back(new myequal(inum));
			break;
		default:
			break;
	}
	return;
}

void logicrule::parseLogicOperand(){
	char ch = str[pos];
	while(pos<str.size() && !isspace(str[pos]))
		++pos;
	if(ch == 'a')
		operands.push_back(1);					//and
	else
		operands.push_back(0);
	return;	  
}

bool logicrule::evaluate(int a){
	if(rules.empty())	return false;
	vector<comparerule*>::iterator ruleIter = rules.begin();
	vector<int>::iterator operandIter = operands.begin();
	bool res = (*ruleIter)->evaluate(a);
	ruleIter++;
	while(ruleIter != rules.end() && operandIter != operands.end()){		//'and' precedence to 'or' is not implemented
		if(*operandIter == 1)
		  res &= (*ruleIter)->evaluate(a);
		else
		  res |= (*ruleIter)->evaluate(a);
		
		if((*operandIter == 1 && !res)
		|| (*operandIter == 0 && res))
		  break;
		ruleIter++;
		operandIter++;		  
	}
	return res;
}

void determineRules(int *numbers, int numberCount, string *rules, int ruleCount)
{
    vector<logicrule*> logicrules;
	for(int i=0;i<ruleCount;++i){
		logicrules.push_back(new logicrule(rules[i]));
	}
	printf("output:");
	for(int i=0;i<numberCount;++i){
		int found = 0;
		vector<logicrule*>::iterator iter = logicrules.begin();
		while(iter != logicrules.end()){
			if((*iter)->evaluate(numbers[i])){
				printf("%s,", (*iter)->getkey());
				found = 1;
				break;
			}
			++iter;
		}
		if(found==0)
		  printf("none,");
	}
	printf("\n");
	for(size_t i =0;i<logicrules.size();++i){
		delete logicrules[i];
		logicrules[i] = 0;
	}
}

int main(int argc, char ** argv)
{
    string str;
	getline(cin, str);
	int* numbers = new int[str.size()]();
	int ncount = splitStr2IntArray(str, numbers);
    
	string* rules = new string[10]();
	str.clear();
	int rcount = 0;
    while(getline(cin, str)!= 0 && !str.empty()) {
        rules[rcount++] = str;
		str.clear();
    }
    determineRules(numbers, ncount, rules, rcount);
    return 0;
}
