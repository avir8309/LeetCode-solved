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
    ListNode* reverse(ListNode* head,ListNode* last){
        if(head==last){
            return head;
        }
        
        ListNode* x=reverse(head->next,last);
        x->next=head;
        head->next=nullptr;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* start=head;
        ListNode* end=head;
        ListNode* temp=head;
        vector<pair<ListNode*,ListNode*>>v;
        while(temp){
            cnt++;
            if(cnt==k){
                end=temp;
                v.push_back({start,end});
                temp=temp->next;
                start=temp;
                cnt=0;
            }
            else{
                temp=temp->next;
            }
            
        }
        ListNode* z=nullptr;
        if(cnt>0){
            z=start;
        }
        ListNode* a=head;
        vector<pair<ListNode*,ListNode*>>f;
        for(int i=0;i<v.size();i++){
            auto x=v[i];
            a=reverse(x.first,x.second);
            f.push_back({a,x.second});
            
        }
        for(int i=0;i<f.size()-1;i++){
            f[i].first->next=f[i+1].second;

        }
        if(z){
            f[f.size()-1].first->next=z;
        }


        
        return v[0].second;
    }
};