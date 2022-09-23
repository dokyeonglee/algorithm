#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& arr, int left, int right){
	
	int random_idx = left + rand() % (right - left);
	swap(arr[random_idx], arr[right]);
	
	int pivot = arr[right];
	int i = left;
	
	for(int j = left; j < right; j++){
		if(arr[j] < pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	
	swap(arr[right], arr[i]);
	
	return i;
	
}

int quick_select(vector<int>& arr, int left, int right, int k){
	if(left == right){
		return arr[left];
	}
	int idx = partition(arr, left, right);
	if(idx == k){
		return arr[k];
	}else if(idx > k){
		return quick_select(arr, left, idx - 1, k);
	}else{
		return quick_select(arr, idx + 1, right, k);
	}
}

int kth(vector<int> &a, int k) {
    k--;
    k = a.size() - k;
	int ans = quick_select(a, 0, a.size() - 1, a.size() - k);
	return ans;
}
