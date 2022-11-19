/*The idea is, simply build Max Heap without caring about the input. Start from the bottom-most and rightmost internal node of Min-Heap and heapify all internal modes in the bottom-up way to build the Max heap.

Follow the given steps to solve the problem:

Call the Heapify function from the rightmost internal node of Min-Heap
Heapify all internal nodes in the bottom-up way to build max heap
Print the Max-Heap
*/
void convertmaxheap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left < n && arr[left] > arr[largest]{
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }
    if(i != largest){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}