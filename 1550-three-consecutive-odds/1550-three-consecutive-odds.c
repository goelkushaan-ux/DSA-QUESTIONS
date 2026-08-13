bool threeConsecutiveOdds(int* arr, int arrSize) {
    if(arrSize<3) return false;
    for(int i=1 ; i<arrSize-1;i++)
        if(arr[i]%2==1 &&arr[i-1]%2==1 &&arr[i+1]%2==1) return true;
    return false;
}