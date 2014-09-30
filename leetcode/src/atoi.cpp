/*
 * implement atoi(const char*). ps, do you really know the logic of <stdlib> atoi() ?
 *
 */
#include "../include/preliminary.h"

class Solution{
public:
    int myatoi(const char* str){
        int preted = 0;
        bool isminus = false, gotvalid = false;
        for(int i=0; str[i] != '\0'; i++){
            if(str[i] == ' '){
                if(!gotvalid)  continue;
                else  break;
            }
            if(str[i] == '+'){
                if(!gotvalid){
                    gotvalid = true;
                    continue;
                }else  break;
            }
            if(str[i] == '-'){
                if(!gotvalid){
                    gotvalid = true;
                    isminus = true;
                    continue;
                }else  break;
            }
            if(str[i] < '0' || str[i] > '9')    break;
            int resi = str[i] - '0';
            if(!isminus){
                if(INT_MAX/10 < preted
                  || (INT_MAX - 10 * preted) < resi){
                    preted = INT_MAX; //positive overflow, INT_MAX is returned
                    break;
                }
            }else if(INT_MIN / 10 > -preted
                    || (INT_MIN + 10 * preted) > -resi){ // avoid reverse INT_MIN to compare!
                preted = INT_MIN;  // negative overflow, INT_MIN is returned
                isminus = false;   //set minus flag to false in trick
                break;
            }
            if(!gotvalid)    gotvalid = true;
            preted = 10 * preted + resi;
        }
        return isminus ? -preted : preted;
    }

    void test_01(){
        vector<string> vec;
        vec.push_back("+2");      // 2
        vec.push_back("++2");     // 0
        vec.push_back(" .3 2");   // 0
        vec.push_back(" 110d");   //110
        vec.push_back(" -13d");   // -13
        vec.push_back(" 2147483648");  //overflow case, return 2147483647(2^31-1)
        vec.push_back(" 2147483647");
        vec.push_back(" -2147483648");
        vec.push_back(" -2147483649");  //overflow case, return -2147483648(-2^31)
        vec.push_back(" --3");    // 0
        vec.push_back(" 14dof");  // 14
        vec.push_back("fx");
        vec.push_back("-(1+2)");  // 0
        for(int i=0; i<(int)vec.size(); i++){
            cout << vec[i] << ": std atoi() " << atoi(vec[i].c_str()) << ", my atoi() " << myatoi(vec[i].c_str()) << endl;
        }
        return;
    }
};

int main(){
    Solution s;
    s.test_01();
    return 0;
}
