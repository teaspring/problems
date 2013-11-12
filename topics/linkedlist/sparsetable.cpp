/*
 * ****************<DataStructureInC++> chapter3, LinkedList******************
 * SparseTable.h, operation on sparse table via vertical and horizontal linked lists. 
 * 
 * test data: 250 class and 5308 students
 * */
#include <iostream>
using namespace std;

/*
 * the student number and class number should be flexible later
 * */
const int StudentNum = 5208;    //assum StudentNum 0-5207
const int ClassNum = 250;        //assum ClassNum 0-249

struct PersonScore{
    int ClassID;
    int StudentID;
    char Score;
    PersonScore* NextStudentInClass;
    PersonScore* NextClassOfStudent;
    PersonScore(int cId, int sId, int score):
        ClassID(cId), StudentID(sId), Score(score){}
};

class PSLList{
    public:
        void Init(char grades[StudentNum][ClassNum]);
        void Insert(int, int, char);
        char Find(int, int);
        void Delete(int, int);
    private:
        PersonScore* StudentHead[StudentNum];
        PersonScore* StudentTail[StudentNum];
        PersonScore* ClassHead[ClassNum];
        PersonScore* ClassTail[ClassNum];
};

void PSLList::Init(char grades[StudentNum][ClassNum]){
    int i=0, j=0;
    while(i < ClassNum){
        ClassHead[i] = ClassTail[i] = 0;        
    }

    while(j < StudentNum){
        StudentHead[j] = StudentTail[j] = 0;
    }
    for(i=0; i<ClassNum; i++){
        for(j=0; j < StudentNum; j++){
            if(grades[i][j] == 0)
              continue;
            PersonScore* node = new PersonScore(i, j, grades[i][j]);
            //horizontal, linked list for one class
            if(ClassTail[i] == 0){
                ClassHead[i] = ClassTail[i] = node;    
            }else{
                ClassTail[i]->NextStudentInClass = node;
                ClassTail[i] = node;
            }

            //vertical, linked list for one student
            if(StudentTail[j] == 0){
                StudentHead[j] = StudentTail[j] = node;
            }else{
                StudentTail[j]->NextClassOfStudent = node;
                StudentTail[j] = node;
            }
        }
    }
}

//in each linked list of class, all the elements in order of student ID
void PSLList::Insert(int cID, int sID, char grade){
    if(cID >= ClassNum || sID >= StudentNum)
        return;                                //currently not support adding new class and student
    PersonScore* newScore = new PersonScore(cID, sID, grade);
    PersonScore* cur = ClassHead[cID];        //horizontal, linked list of class
    PersonScore* prev = 0;
    while(cur != 0 && cur->StudentID < sID){
      prev = cur;
      cur  = cur->NextStudentInClass;
    }
    if(cur == 0){                    //prev is tail
        ClassTail[cID]->NextStudentInClass = newScore;
        ClassTail[cID] = newScore;
    }else{
        prev->NextStudentInClass = newScore;
        newScore->NextStudentInClass = cur;
    }

    cur = StudentHead[sID];            //vertical, linked list of student
    prev = 0;
    while(cur != 0 && cur->ClassID < cID){
      prev = cur;
      cur  = cur->NextClassOfStudent;
    }
    if(cur == 0){                    //prev is tail
        StudentTail[sID]->NextClassOfStudent = newScore;
        StudentTail[sID] = newScore;
    }else{
        prev->NextClassOfStudent = newScore;
        newScore->NextClassOfStudent = cur;
    }
}

/*
 * search along either linked list is OK
 * */
char PSLList::Find(int cID, int sID){
    if(cID >= ClassNum || sID >= StudentNum)
        return 0;
    PersonScore* cur =  ClassHead[cID];            //vertical, linked list of class
    while(cur != 0 && cur->StudentID < sID){
        cur = cur->NextStudentInClass;
    }

    if(cur == 0 || cur->StudentID > sID)
        return 0;
    return cur->Score;
}

/*
 * element's positions in two cross linked lists need to be found
 * */
void PSLList::Delete(int cID, int sID){
    if(cID >= ClassNum || sID >= StudentNum)
      return;
    PersonScore* cur = ClassHead[cID];
    PersonScore* prev = 0;
    
    while(cur != 0 && cur->StudentID < sID){
      prev = cur;
      cur  = cur->NextStudentInClass;
    }
    if(cur == 0 || cur->StudentID > sID){                    //till tail or not found
        return;
    }else{                                                    //cur is found
        prev->NextStudentInClass = cur->NextStudentInClass;
    }

    cur = StudentHead[sID];                            //vertical, linked list of student
    prev = 0;
    while(cur != 0 && cur->ClassID < cID){
      prev = cur;
      cur  = cur->NextClassOfStudent;
    }
    if(cur==0 || cur->NextClassOfStudent->ClassID > cID)    //not found
        return;
    else
        prev->NextClassOfStudent = cur->NextClassOfStudent;
    delete cur;
    return;
}

int main(int argc, char* argv[]){
    return 0;
}
