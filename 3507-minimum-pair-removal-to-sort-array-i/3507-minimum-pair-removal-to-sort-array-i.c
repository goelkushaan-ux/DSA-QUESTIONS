#include <stdlib.h>

int check(int *arr,int n){
    for(int i=1;i<n;i++) if(arr[i]<arr[i-1]) return 0;
    return 1;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int n=numsSize;
    int time=0;
    while(check(nums,n)!=1){
        int k=0;
        for(int i=1;i<n-1;i++)
            if(nums[i]+nums[i+1]<nums[k]+nums[k+1]) k=i;
        nums[k]=nums[k]+nums[k+1];
        for(int i=k+1;i<n-1;i++) nums[i]=nums[i+1];
        n--;
        time++;
    }
    return time;
}