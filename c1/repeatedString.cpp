
// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long partialWordCount = 0;
    long wholeWordCount = 0;
    long rem = n % s.size();
    long div = n / s.size();
    
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'a')
           wholeWordCount++; 
    
    if (rem == 0)
        return wholeWordCount * div;
    
    for (int i = 0; i < rem; i++)
        if (s[i] == 'a')
           partialWordCount++;       
    
    return wholeWordCount * div + 
        partialWordCount;
        
}