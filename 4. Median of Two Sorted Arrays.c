/*
Median is the middle number which partitions the sorted array into two halves with same length, even when it comes to two sorted array, the rule will always apply.

Overview of the partition:

  A[i-1]   |   A[i]
          \|/
          /|\
  B[i-1]   |   B[j]
So in this problem, we are to search out the four border numbers A[i-1] and A[i] in array-1 and B[j-1] and B[j] in array-2 to ensure that:

First, max(A[i-1],B[j-1]) is smaller than or equal to min(A[i],B[j]).
Second, len(A[0]...A[i-1])+len(B[0]...B[j-1])==len(A[i]...A[n-1])+len(B[j]...B[m-1]), n and m is the size of the array-1 and array-2 respectively.
Third, to ensure the above two conditions, there must be a equation mid=i+j-1=(m+n-1)/2 and as a result A[i-1] corresponds to B[j] and B[j-1] corresponds to A[i]; so actually we need to search two pairs, which will meet the following requirements: A[i-1]<=B[j] and B[j-1]<=A[i].
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) nums1.swap(nums2);
        int size1 = nums1.size(), size2 = nums2.size(), size = size1+size2;
        int mid = (size-1)/2, l = 0, r = size1-1;
        while(l <= r){
            int m1 = l+((r-l)>>1), m2 = mid-m1;
            if(nums1[m1] > nums2[m2]) r = m1-1;
            else l = m1+1;
        }
        int a = max(r>=0? nums1[r]:INT_MIN, mid-l>=0? nums2[mid-l]:INT_MIN);
        if(size&1) return a;
        int b = min(l<size1? nums1[l]:INT_MAX, mid-r<size2? nums2[mid-r]:INT_MAX);
        return (a+b)/2.0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        return max(Ai_minus_1, Bj);
    }
};
