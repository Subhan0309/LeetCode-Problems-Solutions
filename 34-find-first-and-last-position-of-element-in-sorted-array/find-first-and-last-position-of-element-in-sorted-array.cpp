class Solution {
public:

//  int findStartingIndex(vector<int>& nums, int target) {
//     int start = 0, end = nums.size() - 1, answer = -1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (nums[mid] == target) {
//             answer = mid;
//             end = mid - 1; // move left to find the starting index
//         } else if (nums[mid] < target) {
//             start = mid + 1;
//         } else {
//             end = mid - 1;
//         }
//     }

//     return answer;
// }

// int findEndingIndex(vector<int>& nums, int target) {
//     int start = 0, end = nums.size() - 1, answer = -1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (nums[mid] == target) {
//             answer = mid;
//             start = mid + 1; // move right to find the ending index
//         } else if (nums[mid] < target) {
//             start = mid + 1;
//         } else {
//             end = mid - 1;
//         }
//     }

//     return answer;
// }

// vector<int> searchRange(vector<int>& nums, int target) {
//     int start = findStartingIndex(nums, target);
//     int end = findEndingIndex(nums, target);

//     return {start, end};
// }
std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    std::vector<int> result = {-1, -1};

    // Finding the leftmost position of the target using lower_bound
    auto left = std::lower_bound(nums.begin(), nums.end(), target);

    // Checking if the target is found
    if (left != nums.end() && *left == target) {
        result[0] = left - nums.begin();
    } else {
        // If not found, return [-1, -1]
        return result;
    }

    // Finding the rightmost position of the target using upper_bound
    auto right = std::upper_bound(nums.begin(), nums.end(), target);

    // Decrementing right by 1 to get the rightmost index
    result[1] = right - nums.begin() - 1;

    return result;
}


};