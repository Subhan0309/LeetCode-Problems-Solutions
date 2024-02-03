class SmallestInfiniteSet {
 
public:
    set<int> added;
    int current;
    SmallestInfiniteSet() {
      current=1;
    }
    
    int popSmallest() {
        if(!added.empty())
        {
            int result = *begin(added); // returns the smallest element from the set
            added.erase(begin(added));
            return result;
        }
        else
        {
            return current++;
        }
    }
    
    void addBack(int num) {
        if(num<current)
        {
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */