#include <bits/stdc++.h> 
/*
    Time Complexity: O(N)
    Space Complexity: O(1)

     where N is the given natural number.
*/


int sumOfProperDivisors(int n){

    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
        sum=sum+i;
      }
    }
    return sum;
}
