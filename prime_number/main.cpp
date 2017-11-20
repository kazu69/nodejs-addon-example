#include <stdio.h>
#include <stdbool.h>
#include "prime_number.hpp"

int main()
{
    int number;
    bool result;
    PrimeNumber primeNumber;

    printf("Enters number: ");
    scanf("%d", &number);

    result = primeNumber.isPrime(number);
    if (result == true) {
        printf("Is prime number");
    } else {
        printf("Is not prime number");
    }

    return 0;
}