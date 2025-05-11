class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount = 0;
        bool oddFound = false;

        for(int i = 0 ; i<arr.size(); i++){
            if(arr[i] % 2 != 0){ // means this is odd number
                if(oddCount == 2 && oddFound){
                    return true;
                }
                oddCount++;
                oddFound = true;
            }else{
                oddCount = 0;
                oddFound = false;
            }
        }
        return false;
    }
};