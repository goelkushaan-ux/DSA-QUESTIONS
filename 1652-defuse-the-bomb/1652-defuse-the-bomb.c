/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
     *returnSize = codeSize;
    int* result = (int*)malloc(codeSize * sizeof(int));

    for(int i=0;i<codeSize; i++){
        if(k==0) result[i]=0;
        if(k>0) {
            int sum=0;
            for(int j=1;j<=k;j++)
            sum=sum+code[(i+j)%codeSize] ; 
            result[i]=sum;
        }
        if(k<0) {
            int temp= k*(-1);
            int sum=0;
            for(int j=1;j<=temp;j++)
            sum=sum+code[(i-j+codeSize)%codeSize] ; 
            result[i]=sum;
        }
    }
    return result;
}