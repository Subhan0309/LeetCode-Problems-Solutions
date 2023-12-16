class Solution {
public:
   bool isAnagram(string s, string t) {
       if(s.length()!=t.length())
       {
           return false;
       }
    unordered_map<char, int> myMap;
    //This Loop is inserting values into the map
    for (int i = 0; i < s.length(); i++)
    {
        myMap.insert(make_pair(s[i], 0));
    }

    //This Loop is incrementing the count of characters in a string

    for (int i = 0; i < s.length(); i++)
    {
        myMap[s[i]]++;
    }

    //This is the Loop that checks for anangram

    for (char c : t)
    {
        if (myMap.find(c) != myMap.end())
        {

           if(myMap[c]>0)
           {
               myMap[c]--;
           }
           else
           {
               return false;
           }
        }
        else
        {
            return false;
         
        }
    }

   
    return true;
    
}
};