class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        //we will store indexes in deque
        vector<int> ans;

        //process first k size window 
        for(int i=0; i<k; i++) {

            while(!dq.empty() &&  nums[dq.back()] < nums[i])
                dq.pop_back();
            //insert element
            dq.push_back(i);
        }

        //ans store karlo for 1st window
        ans.push_back(nums[dq.front()]);

        //remaining windows
        for(int i=k; i<nums.size(); i++) {
            //removal
            if(!dq.empty() && i-k >= dq.front()) 
                dq.pop_front();

            //additional
            while(!dq.empty() &&  nums[dq.back()] < nums[i])
                dq.pop_back();
            //insert element
            dq.push_back(i);

            ///ans store
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};