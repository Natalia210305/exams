#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//function to check if the number is prime or not 
bool prime(long long n) {
    if (n<2) {
        return false;
    }
    for (long long i=2 ; i*i<= n ; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

//function to check if the number is a perfect square of a prime number
bool perfectSquare(long long n){
    double squareRoot=sqrt(n);
    long long roundedsquare=round(squareRoot);
    if (roundedsquare * roundedsquare == n) {
        return true;
    }
    else {
        return false;
    }
}

//function to check if the number is a mirrored
long long mirror(long long n){
    long long reversed=0;
    while(n>0){
        long long current = n% 10;
        reversed = reversed *10+ current;
        n/=10;
    }
    return reversed;
}

int main(int argc,char * argv[]) {
    if (argc != 3){
        return 1;
    }
    //user gives the value range to be checked
    long long low = atoll(argv[1]);
    long long high = atoll(argv[2]);
    long long sum=0;
    //check if the number is out of the value range 
    if (low<1 || high>1e15 || low>high) {
        return 1;
    }
    //We calculate the root of the lower limit and the upper limit
    long long low_limit = sqrt(low);
    long long high_limit = sqrt(high);
    for(long long i=low_limit ; i<=high_limit ; i++){
        if(perfectSquare(i*i) && perfectSquare(mirror(i*i)) && prime(i) && prime(mirror(i)) && !(i*i==mirror(i*i))){
            sum+=(i*i);
        }
    }
    //print the sum of the mirror primes of the interval (from low to high)
    printf("%lld\n", sum);
    return 0;
}

