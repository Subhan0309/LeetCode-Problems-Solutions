class Solution {
public:
//  bool checkGood_String(string str) {
//     if (str.length() != 3) {
//         return false;
//     }

//     if ((str[0] == str[1]) && (str[1] == str[2])) {
//         return true;
//     }

//     return false;
// }
// bool isGreator(string str1,string str2)
// {
//     return stoi(str1)>stoi(str2);
// }

// string largestGoodInteger(string num) {
//     string max = "-111";

//     int left = 0;
//     int right = 2;

//     while (right < num.size()) {

//         string holder = num.substr(left, right - left + 1);

//         if (checkGood_String(holder)) {
           
//             if (isGreator(holder,max)) {
//                 max = holder;
//             }
//         }
//         left ++;
//         right++;
//     }

//     return (max == "-111") ? "" : (max);
// }

    string largestGoodInteger(string num) {
        //I keppt this in Decreasing order as we want max good string so we start checking from max
        vector<string> good_strings ={"999","888","777","666","555","444","333","222","111","000"};

        for(auto goodString:good_strings)
        {
            int left=0;
            int right=2;

            while(right<num.size())
            {
                string holder=num.substr(left,right-left+1);

                if(holder==goodString)
                {
                    return holder;
                }

                right++;
                left++;
            }
        }
        return "";
    
    }

};