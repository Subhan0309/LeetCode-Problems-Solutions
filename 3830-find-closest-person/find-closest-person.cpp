class Solution {
public:
    int findClosest(int x, int y, int z) {

        int p1steps = abs(z-x);
        int p2steps = abs(z-y);

        if(p1steps > p2steps){
            return 2;
        }else if(p2steps > p1steps){
            return 1;
        }else if(p2steps == p1steps){
            return 0;
        }
        
        return 0;
    }
};