// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        while(start < n)
        {
            int mid = (n - (n - start)/2);
            if(isBadVersion(mid)) n = mid-1;
            else start = mid+1;
        }
        return isBadVersion(start)?start:isBadVersion(n)?n:n+1;
    }
};