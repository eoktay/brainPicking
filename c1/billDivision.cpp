// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
    int annaCost = 0;
    for (int i = 0; i < bill.size(); i++)
    {
        if (i != k)
            annaCost += bill[i];
    }
    if (b == annaCost / 2)
        cout << "Bon Appetit";
    else
        cout << to_string(b - annaCost / 2);
}