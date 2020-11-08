
const int n = 1e5 + 5, P = 1e9+7;

int A[n+1], B[n+1];
int lowbit(int x) { return x & -x;}
void update(int x) {
    while (x <= n) {
        A[x]++; 
        x += lowbit(x);
    }
}
int get(int x) {
    int ans = 0;
    while (x > 0) {
        ans += A[x]; 
        x -= lowbit(x);
    }
    return ans;
}

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B));
        long ans = 0;

        int ss = 0;
        for (int x : instructions) {
            int p1 = get(x-1), p2 = ss - p1 - B[x];
            ans += min(p1, p2);
            ss++; B[x]++;
            update(x);
        }
        return ans%P;
    }
};