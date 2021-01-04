// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int ret = 0;
    for (int i = 0; i < ar.size(); i++)
        for (int j = i + 1; j < ar.size(); j++)
            if ((ar[i] + ar[j]) % k == 0)
                ret++;
                
    return ret;
}