long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long int sum1=0,sum2=0,count1=0,count2=0;
    for(int i=0;i<nums1Size;i++) {
        sum1+=nums1[i];
        if(nums1[i]==0) count1++;
    }
    for(int j=0;j<nums2Size;j++) {
        sum2+=nums2[j];
        if(nums2[j]==0) count2++;
    }
    if((sum1+count1>sum2 && count2==0) || ( sum1<sum2+count2 && count1==0) ) return -1;
    else if(sum1+count1>=sum2+count2) return sum1+count1;
    else if(sum1+count1<=sum2+count2) return sum2+count2;
    return 0;
}