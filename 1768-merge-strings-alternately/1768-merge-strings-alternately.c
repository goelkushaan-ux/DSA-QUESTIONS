
char* mergeAlternately(char* word1, char* word2) {
    
    int len1 = strlen(word1);
    int len2 = strlen(word2);
     int len = len1 + len2 ;
      char* str= (char*)malloc((len + 1) * sizeof(char));
    int i = 0, j = 0, k = 0;
   while (i < len1 || j < len2) {
        if (i < len1) {
            str[k] = word1[i];
            i++;
            k++;
        }
        if (j < len2) {
            str[k] = word2[j];
            j++;
            k++;
        }
    }
     str[k] = '\0';
    return str;
    }

