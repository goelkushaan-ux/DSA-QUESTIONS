int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int ans = 0;
    int i = 0;
int n=neededTimeSize;
    while(i < n) {
        int sum = neededTime[i];
        int mx  = neededTime[i];
        
        int j = i + 1;
        
        // group of same colors
        while(j < n && colors[j] == colors[i]) {
            sum += neededTime[j];
            if(neededTime[j] > mx)
                mx = neededTime[j];
            j++;
        }

        // remove all except the most expensive one
        ans += (sum - mx);
        
        i = j; // jump to next group
    }

    return ans;
}