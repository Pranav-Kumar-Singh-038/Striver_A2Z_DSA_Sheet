#include <iostream>
#include <vector>
#include <algorithm>
//Optimal : it is hard try to go through it properly

/*There are many ways to systematically generate all permutations of a given sequence.[52] 
One classic, simple, and flexible algorithm is based upon finding the next permutation in 
lexicographic ordering, if it exists. It can handle repeated values, for which case it generates
 each distinct multiset permutation once. Even for ordinary permutations it is significantly more
  efficient than generating values for the Lehmer code in lexicographic order (possibly using the
   factorial number system) and converting those to permutations. It begins by sorting the 
   sequence in (weakly) increasing order (which gives its lexicographically minimal permutation),
    and then repeats advancing to the next permutation as long as one is found. The method goes 
    back to Narayana Pandita in 14th century India, and has been rediscovered frequently.[53]

The following algorithm generates the next permutation lexicographically after a given 
permutation. It changes the given permutation in-place.

Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is 
the last permutation.
Find the largest index l greater than k such that a[k] < a[l].
Swap the value of a[k] with that of a[l].
Reverse the sequence from a[k + 1] up to and including the final element a[n].
For example, given the sequence [1, 2, 3, 4] (which is in increasing order), and given that the 
index is zero-based, the steps are as follows:

Index k = 2, because 3 is placed at an index that satisfies condition of being the largest index 
that is still less than a[k + 1] which is 4.
Index l = 3, because 4 is the only value in the sequence that is greater than 3 in order to 
satisfy the condition a[k] < a[l].
The values of a[2] and a[3] are swapped to form the new sequence [1, 2, 4, 3].
The sequence after k-index a[2] to the final element is reversed. Because only one value lies 
after this index (the 3), the sequence remains unchanged in this instance. Thus the lexicographic 
successor of the initial state is permuted: [1, 2, 4, 3].
*/

/*
How I understood, 2,3,6,5,4,1
for the number 236541 if you want the next permutation you would start looking from the ones place so as to increse it by a small amount
but you would notice that it is the already the largest it can be using 2 digits, 3 or 4 (6541) but it is not the largest in 5 digit(36541)
. So the point here comes that find the index where the ascending order breaks from the end. Now you know you have to find the next biggest value of
36541 where 6541 is already max, you cannot sort it as it bring 1 to the front and the value will decrease. So it means you have to pick the next largest after 3.
Since the value is largest in 3. so you choose 4. Now you swap 3 with 4 as you know 4 will definitly be in the position of 3 i.e 246531. Now you can easily take the
digits after 4 and sort them to get the biggest larger than the 36541
*/
//O(n)
//O(1)
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    std::swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 
//same but with library functions
// void nextPermutation(vector<int>& nums) {
//     auto i = is_sorted_until(nums.rbegin(), nums.rend());
//     if (i != nums.rend())
//         swap(*i, *upper_bound(nums.rbegin(), i, *i));
//     reverse(nums.rbegin(), i);
// }

//Used library function
// void nextPermutation(vector<int>& nums) {
//     next_permutation(begin(nums), end(nums));
// }

int main()
{
 int n;
 std::cin>>n;
 std::vector<int> vec;
 while(n--)
 {
  int x;
  std::cin>>x;
  vec.push_back(x);
 }
 Solution sol;
 sol.nextPermutation(vec);
}