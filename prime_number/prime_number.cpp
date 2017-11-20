#include <stdio.h>
#include <stdbool.h>
#include "prime_number.hpp"

// function definition
int PrimeNumber::isPrime(int number)
{
    bool result = true;
    int i;

    for(i = 2; i < number; ++i) {
        if (number % i == 0) {
            result = false;
            break;            
        }
    }

    return result;
}
