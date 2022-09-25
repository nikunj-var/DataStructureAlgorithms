//insertionsort

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=arr[i];

        while(j > 0 && temp > arr[j]){
            arr[j+1]=arr[j];
            j--;
        }       
        arr[j+1]=temp; 
    }
}

//merge sort

void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;

    int first[n1];
    int second[n2];
    int k=p;
    for(int i=0;i<n1;i++){
        first[i]=arr[k++];
    }
    k=q+1;
    for(int j=0;i<n2;j++){
        second[j]=arr[k++];
    }

    i=0;
    j=0;
    k=0;
    while(i < n1 && j < n2){
        if(first[i] < second[j]){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=second[j++];
        }
    }
    while(i < n1){
        arr[k++]=first[i++];
    }
    while(j < n2){
        arr[k++]=second[j++];
    }
}
void mergesort(int arr[],int s,int e){
    if(s<e){
        int q=(s+e)/2;
        mergesort(arr,s,q);
        mergesort(arr,q+1,e);
        merge(arr,s,q,e);
    }
}

//quicksort
