/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopy(Node* head)
    {
        Node* temp=head;
        while(temp)
        {
            Node* copy=new Node(temp->val);
            Node* nextNode=temp->next;

            copy->next=nextNode;
            temp->next=copy;
            temp=nextNode;
        }
    }
    void copyRandom(Node* head)
    {
        Node* temp=head;
        while(temp)
        {
            Node* copy=temp->next;
            if(temp->random)
            {
                copy->random=temp->random->next;
            }
            else{
                copy->random=NULL;
            }
            temp=temp->next->next;
        }
    }
    Node* deepCopy(Node* head)
    {
        Node dummy(0);
        Node* res=&dummy;

        Node* temp=head;
        while(temp)
        {
            res->next=temp->next;
            res=res->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy.next;
    }
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
        insertCopy(head);
        copyRandom(head);
        return deepCopy(head);
    }
};