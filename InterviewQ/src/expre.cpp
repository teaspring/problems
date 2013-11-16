/*
 * 20130714 Amazon online programming question2, expression interprete
 * 
 * test data:
 * 2+(3*3-2)
 * 9-3*(2+2)/6+1
 * */

#include "../header/expre.h"

/*
 * iteratation function without OO design is ugly, too much duplicate which has to be
 *
 * vital problem of this solution is: expression has some internal recursion natively,like (expression) nested in factor
 * of term*\/. it is difficult to solve it forward in one function
 * 
 *
 * */
int procString(string input){
    size_t pos=0; 
    int lastRes = 0,res =0;
    bool bMinus=false;
    const char* inArr = input.c_str();
    
    while(pos < strlen(inArr)){
        char c = inArr[pos++];
        switch(c){
            case '*':
                c = inArr[pos++];
                if(c == '('){
                  size_t tmp = pos;
                  while(inArr[tmp++]!=')');
                  string str(inArr+pos, tmp-pos-1);
                  res *= procString(str);
                  pos = tmp;
                }else
                    res *= atoi(&c);
                break;
            case '/':
                c = inArr[pos++];
                if(c == '('){
                  size_t tmp = pos;
                  while(inArr[tmp++]!=')');
                  string str(inArr+pos, tmp-pos-1);
                  res /= procString(str);
                  pos = tmp;
                }else
                    res /= atoi(&c);
                break;
            case '+':        
                if(bMinus)    
                  lastRes -= res;
                else 
                  lastRes += res;        //after res combined with lastRes, res can be reset
                res = 0;
                bMinus = false;
                c = inArr[pos++];
                if(c == '('){
                    size_t tmp = pos;
                    while(inArr[tmp++]!=')');
                    string str(inArr+pos, tmp-pos-1);
                    res = procString(str);
                    pos = tmp;
                }else
                  pos--;
                break;
            case '-':
                if(bMinus)    lastRes -= res;
                else lastRes += res;
                bMinus = true;
                c = inArr[pos++];
                if(c == '('){
                    size_t tmp = pos;
                    while(inArr[tmp++]!=')');
                    string str(inArr+pos, tmp-pos-1);
                    res = procString(str);
                    pos = tmp;
                }else
                  pos--;
                break;
            default:        //number
                if(bMinus){
                    res = 0 - atoi(&c);
                    bMinus = false;
                }
                else{
                    res = atoi(&c);
                }
                break;
        }
    }
    if(bMinus){
        res = lastRes - res;
    }else
        res += lastRes;
    return res;
}

/*
 * OO design of this question, much, much better than iterate function!
 * */
int expreInter::expression(){    //expression = term +/- term (loop)
    int val = term();
    while(pos < inStr.length()){
        if(ch == '+')            //known char is beginning followed by fixed section.
            val += term();
        else if(ch == '-')
            val -= term();
        else if(ch == ')')        //known char is end. expression is over
            break;
        else
            break;
    }
    return val;   
}

int expreInter::term(){            //term = factor */ factor (loop)
    int val = factor();
    while(pos<inStr.length()){
        ch = inStr[pos++];
        if(ch == '*'){
            val *= factor();
        }
        else if(ch =='/'){
            val /= factor();
        }
        else
            break;
    }                            //ch points to next char beyond term
    return val;
}

int expreInter::factor(){        //factor = (-)number or (expression)
    int val = 0;
    int minus = 1;
    while(pos < inStr.length()){
        ch = inStr[pos++];
        if(ch == '(')
            return expression();
        if(ch == '-'){            //support minus decimal, only '-' ahead of number is minus
            if(val==0){
                minus = -1;
                continue;
            }
        }else if(isdigit(ch)){ //support tens/hundreds decimal 
            val = 10*val + atoi(&ch);
            continue;
        }
        --pos;                //ch(inStr[pos++]) is not processed, turn back pos to let others handle it
        break;
    }
    return val * minus;
}

void expreInter::interpret(){
    cout<<expression()<<endl;
}

int main(int argc, char* argv[]){
    string s;
    while(cin>>s){
        expreInter* myInter = new expreInter(s);
        myInter->interpret();
        delete myInter;
        myInter=0;
    }
    return 0;
}
