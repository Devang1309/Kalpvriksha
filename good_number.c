#include <stdio.h>
#define MOD 1000000007

long long calculate_good_number(long long base, long long exponent){
    long long count = 1;

    while(exponent>0){
        if(exponent%2 == 1){
            count = (count*base)%MOD;
        }

        base = (base*base)%MOD;
        exponent /= 2;
    }

    return count;
}

int count_good_number(long long length){
    long long even = (length+1)/2;
    long long odd = length/2;

    long long even_part = calculate_good_number(5, even);
    long long odd_part = calculate_good_number(4, odd);

    long long result = (even_part*odd_part)%MOD;

    return result;
}

int main(){
    long long good_number_length;
    printf("Enter the length of good number:\n");
    scanf("%lld", &good_number_length);

    int answer = count_good_number(good_number_length);

    printf("Total good numbers: %d", answer);

    return 0;
}