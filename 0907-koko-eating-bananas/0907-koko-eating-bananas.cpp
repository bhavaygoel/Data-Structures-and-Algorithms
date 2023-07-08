class Solution {
public:
    bool isValid(vector<int>& piles, int h, int speed) {
        int time = 0;
        for (int bananas : piles) {
            time += (bananas + speed - 1) / speed; 
            if (time > h) {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValid(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
