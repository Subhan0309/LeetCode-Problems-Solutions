class Solution {
public:
    bool containsZero(int num){
        int n = 0;
        while(num != 0){
            n = num % 10;
            if (n == 0){
                return true;
            }
            num = num / 10;
        }

        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> answer;
        for(int i = 1 ; i <= n ; i++){
            int a = n - i;
            int b = n - a;
            if(!containsZero(a) && !containsZero(b)){
                answer.push_back(a);
                answer.push_back(b);
                return answer;
            }
        }

        return answer;
        
    }
};