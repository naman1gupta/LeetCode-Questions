class Solution {
public:
    int pivotInteger(int n) {
        int num=(n*n);
        num+=n;
        num/=2;
        int num1=sqrt(num);
        if((num1*num1) == num){
            return num1;
        }
        else{
            return -1;;
        }
    }
};