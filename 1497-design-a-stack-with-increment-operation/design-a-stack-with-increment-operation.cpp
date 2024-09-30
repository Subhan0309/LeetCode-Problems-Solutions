class CustomStack {
    int max;
    int c_size;
    vector<int> stak;
public:
    CustomStack(int maxSize) {
        stak.resize(maxSize);  // Resize to maxSize
        max = maxSize;
        c_size = 0;  // Initialize to 0, representing an empty stack
    }
    
    void push(int x) {
        if (c_size < max)  // Only push if there is space
        {
            stak[c_size] = x;  // Insert at current size
            c_size++;  // Increment size
        }
    }
    
    int pop() {
        if (c_size > 0)  // Check if the stack is not empty
        {
            c_size--;  // Decrement size first to point to the last element
            return stak[c_size];  // Return the last element
        }
        else
        {
            return -1;  // Return -1 if the stack is empty
        }
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i < c_size; i++)  // Increment only up to the current stack size
        {
            stak[i] += val;
        }
    }
};
