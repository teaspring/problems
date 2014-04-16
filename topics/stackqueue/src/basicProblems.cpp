/*
 * move elements of one stack to another stack with the same order.only one variable can be used
 * */

/*
 * sort a stack in ascending order. use another stack and one variable only
 * */

/*
 * move elements of one queue to another queue with reverse order.
 * */

/*
 * sort a queue in ascending order. user another queue and one variable only
 * */

/*
 * we have many flexible stacks.if the stack gets too high, we will start a new stack. Define SetOfStacks, it is composed of several stacks. It will create a new sub stack once the previous one exceeds capacity. push() and pop() behave identically to a single stack.
 * */

/*
 * implement a queue using two stacks
 * */

/*
 * solution: the difference between queue and stack is the order that element is poped. we have two stacks, one for insert(enqueue) as normal; when dequeue is called, another stack is used to keep all elements moved from the first stack.
 * lazy move: when deque is called after enqueue, we moved all elements from stack1 to stack2 and pop; when enqueue is called after dequeue, we move all elements from stack2 to stack1 and push.
 * */
