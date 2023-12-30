class Element {
public:
    int sum;
    vector<int> values;

    Element(int s, vector<int> v) : sum(s), values(v) {}

    // Define comparison operator for set
    bool operator<(const Element& e) const {
        return sum > e.sum; // Use greater than for a min heap
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> answer;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return answer;
        }

        // Use priority queue to keep track of the smallest sum pairs
        priority_queue<Element> pq;

        // Initialize with the first element from each array
        pq.push(Element(nums1[0] + nums2[0], { 0, 0 }));

        // Use a set to keep track of visited pairs
        set<pair<int, int>> visited;
        visited.insert({ 0, 0 });

        // Continue until we find k pairs or the priority queue is empty
        while (k > 0 && !pq.empty()) {
            Element current = pq.top();
            pq.pop();

            int i = current.values[0];
            int j = current.values[1];

            // Add current pair to the answer
            answer.push_back({nums1[i],nums2[j]});

            // Check the pair (i, j+1)
            if (j + 1 < nums2.size() && visited.find({ i, j + 1 }) == visited.end()) {
                pq.push(Element(nums1[i] + nums2[j + 1], { i, j + 1 }));
                visited.insert({ i, j + 1 });
            }

            // Check the pair (i+1, j)
            if (i + 1 < nums1.size() && visited.find({ i + 1, j }) == visited.end()) {
                pq.push(Element(nums1[i + 1] + nums2[j], { i + 1, j }));
                visited.insert({ i + 1, j });
            }

            k--;
        }

        return answer;
    }
};