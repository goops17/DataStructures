# 30k random floating point number sum
Using vectors, recursion and algorithms - solve this problem. (No need for OOP - just use structured C++ and functions for this program)

Background:

Summing a linear list of values is pretty straight forward but simple summation of n numbers in sequence is very inefficient and can cause numerical errors in computing especially when using floating point precision.

The Kahan summation algorithm reduces the numerical error by adding a sequence of decimal numbers using a separate running compensation (basically a variable to accumulate small errors).  Now, this is not useful if we're adding 10, 100 even 1000 number but what about much larger numbers!

The error in adding a large number of values grows proportionally to n. With the Kahan algorithm the numerical error is independent of n, so a large number of values can be summed with an error that only depends on decimal precision. 

Here is the pseudocode for the algorithm (wikipedia):

    function KahanSum(input)

      var sum = 0.0

      var c = 0.0

      for i = 1 to input.length 

        var y = input[i] - c

        var t = sum + y

        c = (t - sum) - y

        sum = t

      next i

    return sum

In this program, you will write a program that uses three methods to sum floating point numbers stored in a vector.  You will generate 30000 random floating point doubles within the range of 100.0 to 500.0.  You will then create three functions - 1) will use the Kahan Summation Algorithm to provide a sum of the vector values 2) will simply add them using a regular loop and 3) will use a recursive function with a base case of vector.empty().  Perform #3 last because you will have to pop off the values as you sum them in order to meet your base case.  

In addition, you will use the elapsed time link to calculate the elapsed time taken for each method to sum the vector values.
