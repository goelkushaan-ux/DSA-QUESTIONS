int romanToInt(char* s) {
    int n=0;
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]=='I') n++;
        if(s[i]=='V') n=n+5;
        if(s[i]=='X') n=n+10;
        if(s[i]=='L') n=n+50;
        if(s[i]=='C') n=n+100;
        if(s[i]=='D') n=n+500;
        if(s[i]=='M') n=n+1000;
        if(i<strlen(s)-1 && (s[i+1]=='V'||s[i+1]=='X')&& s[i]=='I') n=n-2;
        if(i<strlen(s)-1 && (s[i+1]=='L'||s[i+1]=='C')&& s[i]=='X') n=n-20;
        if(i<strlen(s)-1 && (s[i+1]=='D'||s[i+1]=='M')&& s[i]=='C') n=n-200;
    }
    return n;
}