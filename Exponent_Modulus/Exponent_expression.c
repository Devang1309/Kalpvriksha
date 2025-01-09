#include <stdio.h>

long long exponent_expression(long long a, long long b, long long c) {
    long long result = 1;  
    a = a % c;  

    if (a == 0) return 0;  

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % c;
        }
        
        b /=2;  
        a = (a * a) % c;  
    }
    return result;
}

int main() {
    long long a, b, c;

    printf("Enter the base (a): ");
    scanf("%lld", &a);
    
    printf("Enter the exponent (b): ");
    scanf("%lld", &b);
    
    if(b<0){
    	printf("Error: Negative exponent");
    	return 0;
	}
	
    
    printf("Enter the modulus (c): ");
    scanf("%lld", &c);
    
    if(c==0){
    	printf("Error: Use numbers correctly");
    	return 0;
	}

    
    long long result = exponent_expression(a, b, c);
    printf("The result of %lld^%lld %% %lld is: %lld\n", a, b, c, result);

    return 0;
}
