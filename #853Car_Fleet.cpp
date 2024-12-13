class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>pair;
        int n=position.size();
        for(int i=0;i<n;++i){
            pair.push_back({position[i],speed[i]});

        }
        sort(pair.rbegin(),pair.rend());//sort vector of pairs in descending order on basis of
                                        //first value of pair
        vector<double>stack;
        for(auto &p:pair){
           stack.push_back((double)(target - p.first) / p.second);
           if(stack.size()>=2&&stack.back()<=stack[stack.size()-2]) stack.pop_back();
        }
        return stack.size();
    }
};

// T.C=O(nlogn)
// S.C.=O(n)

// Approach:
// 1. we will store pairs of position and speed in a vector and sort in decreasing order this is because we wont to check from the car which is near the target line as the behind cars can vary speed any time so we cant have a proper calculation.

// 2. we will push the time taken by each care to reach target into stack after the stack size is 2 we will check whether the time taken by latest car is less than previous car if it is means they will form a fleet and will move with the speed of slower car and will take time of that car only(in this case stack[stack.size()-2])).

// 3. Hence we pop out the newly inserted ele in stack.
// 4. the number of fleets is equal to the number of elements in stack
