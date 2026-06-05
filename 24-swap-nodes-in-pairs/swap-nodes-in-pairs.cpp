/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      //https://www.youtube.com/watch?v=lIar1skcQYI&t=97s

      //or  Reverse Nodes in K Group Size of LinkedList , here k=2
      int k=2;

      ListNode* temp=head; ListNode* next;ListNode* prev=nullptr;
      ListNode* kthnode;

      if(head==nullptr || head->next==nullptr ) return head;
      //to find each portion of size k and reverse them 
      while(temp!=nullptr)
      {
        //to find kth node , to find partition ending node ,partition start=temp
        kthnode=findkth(temp,k);
        //if we cant find kth node bcz at last there is no sufficient k nodes , then no need to swap
        if(kthnode==nullptr)
        {
            if(prev) // https://chatgpt.com/s/t_6a22ef7893708191ab1751cb14e5170b
                prev->next=temp;

            break;
        }

        next=kthnode->next;
        kthnode->next=nullptr; //to cut partition one from 2 and pass 1 to reverse
        reverseList(temp);//reverse k elements from temp
        //to change head to reversed new first nodec, but how to find which is first partiton?
        if(temp==head) //then first partition 
        {
            head=kthnode;
            
        }
        else // for second partition we need to connect it to temp
        //remember before updating temp do this step ,else working will be wrong
        {
            prev->next=kthnode;//note after reversing partition 2 only we join partition 1 end to partition 2 starting (i.e) kth node ,
            //this above code assigns 1st partition's end ->next=2nd partition's new(i.e kthnode)( after reverse comes to 1ts node ) only in 2nd partition's corrwsponding loop only , in 2nd time of loop only , 1st loop end attached to 2nd ones new
        }
         prev=temp; //store temp value before updating
        temp=next;
        
      }

      return head;
    }
      ListNode* findkth(ListNode* temp,int k)
      {
        k--;
        while(temp!=nullptr && k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
      }

      ListNode* reverseList(ListNode* head) {
        ListNode* next=nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        return prev;
      }
    
};