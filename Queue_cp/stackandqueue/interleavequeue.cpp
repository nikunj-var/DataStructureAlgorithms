//interleave the first half od the queue with the second half

/*
Using Stack
Following are the steps to solve the problem: 

Push the first half elements of the queue to stack. 
Enqueue back the stack elements. 
Dequeue the first half elements of the queue and enqueue them back. 
Again push the first half elements into the stack. 
Interleave the elements of queue and stack. 
*/

/*
Using Queue
We can also solve the given problem by using a queue instead of a stack. The idea is to move the first half to another queue, and then push values from the temporary queue and original queue into the original queue. The original queue will get converted to the interleaved queue after the operations.

Steps to solve : 
Make a temporary queue and push the first half of the original queue into the temp queue.
Till the temp queue is empty
Pop the front of the temp queue and push it to the original queue
Pop the front of the original queue and push it to the original queue
The original queue is converted to the interleaved queue.
*/