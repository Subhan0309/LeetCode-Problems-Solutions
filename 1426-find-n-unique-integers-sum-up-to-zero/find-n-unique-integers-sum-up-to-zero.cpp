class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer(n,0);
        int sum=0;
        for(int i = 1; i < n ; i++){
            answer[i] = i;
            sum+=i;
        }
        
        answer[0] = -sum;

        return answer;
    }
};