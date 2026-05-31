#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* curr =  head;
        
        while(curr != NULL){

            for(int i=0; i<m; i++){
                curr = curr->next;
            }
            ListNode* temp = curr->next;

            for(int i=0; i<n; i++){
                temp = temp->next;
            }
            curr->next = temp;
            curr = temp;
        }
        
        return head;
        
    }
};
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int x, int y) {
        if(x == y){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* prevX = NULL;
        ListNode* currX = NULL;
        ListNode* prevY = NULL;
        ListNode* currY = NULL;
        

        while(temp != NULL){

            if (temp->val == x){
                prevX = prev;
                currX = temp;
            } 
            if (temp->val == y){
                prevY = prev;
                currY = temp;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!currX || !currY) return head;
        
        // swapping
        ListNode* t = currX->next;  

        prevX->next = currY;
        prevY->next = currX;
        currX->next = currY->next;
        currY->next = t;
        
        return head;

    }
};

int main(){
    return 0;
}
int main(){
    return 0;
}