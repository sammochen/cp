vector<int> toVec(ListNode* head) {
    vector<int> A;
    while (head) {
        A.push_back(head->val);
        head = head->next;
    }
    return A;
}

ListNode* toList(vector<int>& A) {
    ListNode* ans = new ListNode(-1);  // sentinel
    auto cur = ans;
    for (int i = 0; i < A.size(); i++) {
        cur->next = new ListNode(A[i]);
        cur = cur->next;
    }
    return ans->next;
}
