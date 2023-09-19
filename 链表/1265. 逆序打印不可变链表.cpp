/*
递归实现即可
*/
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(!head) return;
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};
