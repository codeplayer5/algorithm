/* C++ program for Memoized version 
for nth Fibonacci number */
//#include <bits/stdc++.h> 
#include <iostream>

#define NIL -1 
#define MAX 100 

int lookup[MAX]; 

void initialize() 
{ 
	for (int i = 0; i < MAX; i++) 
		lookup[i] = NIL; 
} 

int fib(int n) 
{ 
    // if you have not calculated fib(n), calculate
	if (lookup[n] == NIL) 
	{ 
		if (n <= 1)         // fib(0) is 0, fib(1) is 1
			lookup[n] = n;  // end recursion
		else
			lookup[n] = fib(n - 1) + fib(n - 2); 
    } 

    return lookup[n]; 
} 

int main () 
{ 
	int n = 40; 
	initialize(); 
	std::cout << "Fibonacci number is " << fib(n) << std::endl; 
	return 0; 
} 
