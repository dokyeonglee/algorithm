#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int partition(vector<int>& arr, int left, int right){
	
	int random_idx = left + rand() % (right - left + 1);
	swap(arr[random_idx], arr[right]);
	
	int pivot = arr[right];
	int i = left - 1;
	
	for(int j = left; j < right; j++){
		if(arr[j] <= pivot){
            int temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
		}
	}
	
    int temp = arr[right];
    arr[right] = arr[i + 1];
    arr[i + 1] = temp;
    
	return i + 1;
	
}

int quick_select(vector<int>& arr, int left, int right, int k){
	if(left == right){
		return arr[left];
	}
	int idx = partition(arr, left, right);
	if(idx - left + 1 == k){
		return arr[idx];
	}else if(idx - left + 1 > k){
		return quick_select(arr, left, idx - 1, k);
	}else{
		return quick_select(arr, idx + 1, right, k - (idx - left + 1));
	}
}

int kth(vector<int> &a, int k) {
	if(is_sorted(a.begin(), a.end())){
		return a[k - 1];
	}
	bool check = true;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != a[0]){
			check = false;
			break;
		}
	}
	if(check){
		return a[0];
	}
	int ans = quick_select(a, 0, a.size() - 1, k);
	return ans;
}