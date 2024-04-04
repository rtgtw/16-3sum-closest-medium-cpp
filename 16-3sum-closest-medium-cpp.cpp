/*

3sum closest 


Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



Solution: 
We are going to employ a two pointer approach 

First step is to Sort the array

After sorting, our next step is to set up a counter for the difference
The goal is to find a triplet that is the closest to the target number

we can create diff that tracks the sum of the triplets

diff = target - triplets

if diff is 0 that means it is exactly the same as the target and we can
continue from there

we want to store the diff if it is the smallestValue
we can initialize the smallest value to a larger number at first

if the diff is larger than the target then we want to decrement high
if the diff is smaller than the target then we want to increment low


*/


//We need the algorithm header for absolute value and sort
//We can include limits to represent the max int value
#include <limits.h>
//for absolute value
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>


class Solution {

public:
	int threeSumClosest(std::vector<int>& arr, int target);

};

int Solution::threeSumClosest(std::vector<int>& arr, int target) {

	//First thing we want to do is sort the array 
	std::sort(arr.begin(), arr.end());

	//We need to have a counter of the closest sum(sum of triplets) to the target
	//We initialize closestSum to a larger number because it will decrease 
	//Once we iterate through the triplets 
	int closestSum = INT_MAX;

	//Create a variable diff to represent the difference between
	//the target number and the sum of the triplets
	int diff;

	//If diff is smaller than the closestSum then update closestSum

	//We want to initialize the left and right pointers that will be used 
	//to represent the other two elements while scanning through the array

	int result;
	int left;
	int right;
	int tripletSum;


	//Create a for loop to iterate through each element within the array,
	//This for loop will only go from 0 to arr . size - 2 since we need 
	//triplets 
	for (int i = 0; i < arr.size() - 2; i++) {
		//We want to initialize the left and right pointers that will be used 
	//to represent the other two elements while scanning through the array
		left = i + 1;
		right = arr.size() - 1;

		//Now we can create a while loop to continue iterating through 
		//the array until each element has been visted, which is when left cross right
		while (left < right) {

			tripletSum = arr[i] + arr[left] + arr[right];
			//find the diff between the target and the triplets
			//we want to find the absolute value of diff 
			diff = std::abs(target - tripletSum);


			if (diff == 0 && !(result == INT_MAX)) {
				closestSum = diff;
				result = tripletSum;
				left++;
				left++;
				continue;
			}
			if (diff < closestSum) {
				closestSum = diff;
				result = tripletSum;
			}
			if (tripletSum > target) {
				right--;
			}
			else if (tripletSum < target) {
				left++;
			}

		}

	}
	return result;
}


int main() {

	Solution solution;

	std::vector<int> array1 = { -1,2,1,-4 };
	std::vector<int> array2 = { 0,0,0 };
	std::vector<int> array3 = { 0,1,2 };

	int target = 1;

	std::cout << solution.threeSumClosest(array3,target);

	return 0;



	//Time complexity O(n^2)
	//Space Complexity O(1)
	//Time taken: 2.5H
}