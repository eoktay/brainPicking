// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> colours;
    int ret = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        colours[ar[i]]++;
    }
    for (unordered_map<int, int>::iterator it = colours.begin(); 
        it != colours.end(); it++)
    {
        // cout << it->first << ": " << it->second << endl;
        ret += it->second / 2;
    }

            
    return ret;
}