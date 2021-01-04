int countingValleys(int steps, string path) {
    bool neg = false;
    int ret = 0;
    int count = 0;
    for (size_t i = 0; i < path.size(); i++)
    {
        if (path[i] == 'U')
            count++;
        else
            count--;
            
        if (count < 0)
            if (!neg)
                neg = true;
                
        if (count >= 0)
        {
            if (neg)
            {
                neg = false;
                ret++;
            }
        }
            
    }
    return ret;
}