//function to check list is circular or not
bool isCircular(Node *head)
{
  Node* temp=head;
  while(temp->next!=head){
      if(temp->next == NULL)
        return false;
        temp=temp->next;
  }
  return true;
}
