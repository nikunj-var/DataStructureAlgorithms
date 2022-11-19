int countsize(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=0){
        count++;
        temp=temp->next;        
    }
    return count;
}

void storelist(Node* head,unordered_map<int,int>& mp){
    Node* temp=head;
    while(temp!=0){
        mp[temp->data]++;
        temp=temp->next;        
    }
}
Node* intersection(Node* head,unordered_map<int,int>& mp){
    Node* temp=head;
    Node* newhead;
    Node* newlist=new Node(0);
    newhead=newlist;
    while(temp!=0){
        if(mp[temp->data]!=0){
            newlist->next=new Node(temp->data);
            newlist=newlist->next;
            mp[temp->data]--;
        }
        temp=temp->next;
    }
    return newhead->next;
}

Node* findIntersection(Node* head1, Node* head2)
{
    
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
        
    unordered_map<int,int> mp;
    Node* temp1=head1,*head;
    int m=0,n=0;
    
    m=countsize(head1);
    n=countsize(head2);
    
    if(m < n){
        Node* curr=head1;
        head1=head2;
        head2=curr;
    }
     
    storelist(head1,mp); 
    
    head=intersection(head2,mp);
    return head;
}
