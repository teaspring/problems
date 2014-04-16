/*
 * two binary trees: T1, with millions of nodes,T2 with hundreds of nodes. create a algorithm to decide if T2 is subtree of T1
 * */

/*
 * provide normal algorithm, then simplify and optimize it
 * */
public bool static containsTree(Node* t1, Node* t2){
    if(t2 == 0)        return true;        //empty tree is subtree
    return (subTree(t1, t2));    
}

//r1 is the big one
public bool static subTree(Node* r1, Node* r2){
    if(r1 == 0)        return false;  //big tree empty & subtree still not found
    if(r1->value == r2->value){
        if(matchTree(r1, r2))    return true;
    }
    return (subTree(r1->left, r2) || subTree(r1->right, r2));
}

public bool static matchTree(Node* r1, Node* r2){
    if(r2 == 0 && r1 == 0)    return true;    //nothing left in the subtree
    if(r1 == 0 || r2 == 0)    return false;    //big tree empty & subtree still not found
    if(r1->value != r2->value)    return false;    //data not match
    return(matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right));
}

int main(int, char**){
    return 0;
}


