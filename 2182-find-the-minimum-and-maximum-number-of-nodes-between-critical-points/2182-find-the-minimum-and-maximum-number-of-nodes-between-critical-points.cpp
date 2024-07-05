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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        int index = 0;

        while(nxt!=NULL){
            if(prev!=NULL && curr!=NULL){
                if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
                    criticalPoints.push_back(index);
                }
            }
           
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            index++;
        }

        if(criticalPoints.size()<2){
            return {-1,-1};
        }

        int minDist = INT_MAX;
        int maxDist = criticalPoints.back()-criticalPoints.front();

        for(int i=1;i<criticalPoints.size();i++){
            int dist = criticalPoints[i]-criticalPoints[i-1];
            minDist = min(minDist,dist);
        }

        return {minDist,maxDist};
    }
};