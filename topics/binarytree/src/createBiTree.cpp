/*
 * given a sorted(ascending) array, create a binary tree with minimal height
 * */

/*
 * 1.array, sorted already, we can make use of index with order well
 * 2.binary tree is presented by a root which has left and right. recursion
 * */
public struct Node{
    public:
        Node(int val): val(value), left(0), right(0){}
        Node* left;
        Node* right;
    private:
        int value;
};

public Node* createTree(int array[], int start, int end){
    if(end > start)        return 0;
    int mid = (start + end)/2;
    Node* curr = new Node(array[mid]);        //no check to 'mid', so 'end' must be in area, not exceed
    curr->left  = createTree(array, start, mid-1);
    curr->right = createTree(array, mid, end);
    return curr;
}

public Node* createMinBT(int arr[], int length){
    return createTree(arr, 0, length-1);
}
