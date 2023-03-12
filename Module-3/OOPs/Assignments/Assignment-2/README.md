## Assignment 2


There is a class Adder which has two data members of type 1D int array and int variable. It
has two functions: getdata and numsum. Function getdata accepts non-empty array of
distinct integers from user in 1D int array data member and a targetsum in another data
member. The function numsum adds any two elements from an input array which is equal to
targetsum and return an array of resulting two elements, in any order. If no two numbers
sum up to the target sum, the function should return an empty array. Note that the target sum
is to be obtained by summing two different integers in the array; you can’t add a single
integer to itself in order to obtain the target sum. You can assume that there will be at most
one pair of numbers summing up to the target sum. Use constructor. Use extra variables if
needed

<br />

Input:
Array=[3,5,-4,8,11,1,-1,7] targetsum=15
Output: [8,7]
Input:
Array=[3,5,-4,8,11,1,-1,6] targetsum=15
Output: []

