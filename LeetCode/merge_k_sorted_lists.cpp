// Merge k Sorted Lists [Hard]
// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<size(lists);i++){
            if(lists[i]!=NULL){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* tail=new ListNode(0);
        ListNode* dummy=tail;
        while(!pq.empty()){
            //cout<<pq.size();
            ListNode* smallest=pq.top().second;
            pq.pop();
            if(smallest->next!=NULL){
                pq.push({smallest->next->val,smallest->next});
            }
            tail->next=smallest;
            tail=tail->next;
        }
        return dummy->next;
    }
};