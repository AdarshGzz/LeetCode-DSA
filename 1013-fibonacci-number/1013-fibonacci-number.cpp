class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;

        if(n==0){
            return a;
        }
        if(n==1){
            return b;
        }
        while(n>1){
            int temp = a;
            a = b;
            b = b+temp;
            n--;
        }
        return b;
    }
};