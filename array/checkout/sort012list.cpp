//Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head==NULL)
            return NULL;
        
       Node* zerohead=NULL,*zerotail=NULL,*onehead=NULL,*onetail=NULL,*twohead=NULL,*twotail=NULL;
       
       Node* temp=head;
       while(temp!=NULL){
           switch(temp->data){
               case 0:if(!zerohead){
                        zerohead=temp;
                        zerotail=zerohead;
                        }
                        else{
                           zerotail->next=temp;
                           zerotail=temp;
                        }
                        break;
                case 1:if(!onehead){
                        onehead=temp;
                        onetail=onehead;
                        }
                        else{
                           onetail->next=temp;
                           onetail=temp;
                        }
                        break;
                case 2:if(!twohead){
                        twohead=temp;
                        twotail=twohead;
                        }
                        else{
                           twotail->next=temp;
                           twotail=temp;
                        }  
                        break;
           }
           temp=temp->next;
       }
       
        if(!zerohead && !onehead){
            return twohead;
        }
        if(!onehead && !twohead)
            return zerohead;
        if(!zerohead && !onehead)
            return twohead;
            
        if(zerohead ){
            if(onehead){
                zerotail->next=onehead;
                onetail->next=NULL;
                if(twohead){
                    onetail->next=twohead;
                    twotail->next=NULL;
                }
            }
            else if(twohead){
                zerotail->next=twohead;
                 twotail->next=NULL;
            }
            return zerohead;
        }
        if(onehead){
                if(twohead){
                    onetail->next=twohead;
                    twotail->next=NULL;
                }
            return onehead;    
            }
        return twohead;
    }
};
