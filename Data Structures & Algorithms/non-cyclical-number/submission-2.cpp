class Solution {
public:
    bool isHappy(int n) {
        int fast = sumOfSquares(n), slow = n;
        while(slow!=fast){
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
            slow = sumOfSquares(slow);
        }
        return fast == 1;
    }
private:
    int sumOfSquares(int n){
        int sum = 0;
        while(n!=0){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
};
