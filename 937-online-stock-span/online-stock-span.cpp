class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int count=1;

        if(st.empty())
        {
            st.push({price,count});
        }
        else
        {
            while(!st.empty())
            {
                if(st.top().first<= price)
                {
                    count+=st.top().second;
                    st.pop();                 
                    
                }  
                else
                {
                    break;
                }    
            }
            st.push({price,count});
           
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */