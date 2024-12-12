class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; 
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
        
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            
            
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            
            
            q.push_back(i);
            
            
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};


// T.C.=O(2N)
// S.C.=O(k){at a time deque contains at most k elements}+O(N){used for returning the answer cant be avoided}

// Approach
// 1. we take a dequeue as we can perform operations both from front and back.

// 2. every time we get a greatest element we pop the smaller elements in the queue so the
//     bigger element is at front and decreasing order is maintained.

// 3. if the deque front already has the bigger element we keep pushing the smaller elemnt and to maintain the queue size k(sliding window size) we pop back the out of bound index using the
// check-:
// if(!q.empty()&&q.front()==i-k) q.pop_front();

// 4. since the biggest element of that window will always be in front of queue(decreasing order) we will start pushing our answers in the answer array(front element) as soon as we reach the end of first sliding window i.e. if(i>=k-1) ans.push_back(nums[q.front()]);
