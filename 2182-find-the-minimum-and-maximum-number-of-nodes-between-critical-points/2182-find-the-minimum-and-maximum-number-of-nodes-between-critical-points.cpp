class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> criticalPoints;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        int position = 0;

        // Traverse the linked list
        while (current != nullptr && current->next != nullptr) {
            next = current->next;
            if (prev != nullptr) {
                if ((current->val > prev->val && current->val > next->val) ||
                    (current->val < prev->val && current->val < next->val)) {
                    criticalPoints.push_back(position);
                }
            }
            prev = current;
            current = next;
            position++;
        }
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDistance =min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};
