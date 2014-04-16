/*
 * design a stack which has a function min which returns the mininum element. push, pop, min should be all at O(1) time
 * */

/*
 min operate at O(1) indicates the comparision between elements are dispersed to push() and pop()
solution1: each element has one additional member of the minium element beneath it. when inserted, its minium is the one next to it or its minium
 * */
struct node{
    node(int val, int min, node* pre = 0):
        value(val),
        minium(min),
        next(pre){}
    int value;
    int minium;
    node* next;    
};

//stack implementation on linked list
class MinStack{
    public:
        MinStack(): head(0){}
        void push(int);
        node* pop();
        int peek();
        bool isEmpty();
        int min();
    private:
        node* head;
};

bool isEmpty(){
    return head == 0;
}

void MinStack::push(int val){
    if(isEmpty()){
        head = new node(val, val);
        return;
    }else{
        int min = head->mininum > head->value ? head->value : head->mininum;
        head = new node(val, min, head);
        return;
    }
}

node* MinStack::pop(){
    if(isEmpty())    return 0;
    node* curr = head;
    head = head->next;
    curr->next = 0;
    return curr;
}

int MinStack::peek(){
    if(isEmpty())    return 0;
    return head->value;
}

int MinStack::min(){
    return head->value > head->minium ? head->minium : head->value;
}

/*
 * issue of solution1: each element has an additional member to save minium beneath it, consider many elements may save extra space for the same minium value.
 * plan B without minium member: define another stack to save the minium values, only when new element's value less than head, it will be inserted
 * */


int main(int, char**){
    return 0;
}

