//function to delete from beginning
node* deletefrombeg(node* head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
        node *temp=head,*temp1=head;  
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
          head=head->next;
        
        free(temp1);
    }
    return head;
}
// function to delete node from end
node* deletefromend(node* head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
        node *temp=head,*prev;
        while(temp->next->next!=head){
            temp=temp->next;
        }
        prev=temp->next;
        temp->next=head;
        free(prev);
    }
    return head;
}
//function to delete from pos
node* deletefrompos(node* head,int pos){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        //free(head);
        return NULL;

    }
    else{
        int i=1;
        node *temp=head,*prev;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        prev=temp->next;
        temp->next=temp->next->next;
        free(prev);
    }
    return head;
}