class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

	// Count the number of 0s, 1s and 2s in the array
	for (i = 0; i < nums.size(); i++) {
		switch (nums[i]) {
		case 0:
			cnt0++;
			break;
		case 1:
			cnt1++;
			break;
		case 2:
			cnt2++;
			break;
		}
	}

	// Update the array
	i = 0;

	// Store all the 0s in the beginning
	while (cnt0 > 0) {
		nums[i] = 0;
         i++;
		cnt0--;
	}

	// Then all the 1s
	while (cnt1 > 0) {
		nums[i++] = 1;
		cnt1--;
	}

	// Finally all the 2s
	while (cnt2 > 0) {
		nums[i++] = 2;
		cnt2--;
	}

	// Print the sorted array
 
}

    
};