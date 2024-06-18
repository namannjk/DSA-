    // for upper bound
    
    int j = upper_bound(arr.begin(), arr.end(), x, [](const int& value, const vector<int>& a) {
        return value < a[0];
    }) - arr.begin();
