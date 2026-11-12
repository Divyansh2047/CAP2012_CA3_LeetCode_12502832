class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1, sum = 0;
        while(n > 0){
            int last = n % 10;
            pro *= last;
            sum += last;
            n = n / 10;
        }
    return pro - sum;    
    }
};
