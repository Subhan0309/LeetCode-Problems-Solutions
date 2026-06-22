class Solution {
public:
    string removeStars(string s) {
        vector<char> sequence;

        for( int i = 0 ; i < s.length() ; i++ ){
            if(sequence.size() > 0 && s[i] == '*'){
                sequence.pop_back();
            }else if(s[i] != '*'){
                sequence.push_back(s[i]);
            }
        }

        string result = "";

        for(auto ch: sequence){
            result+=ch;
        }

        return result;
    }
};