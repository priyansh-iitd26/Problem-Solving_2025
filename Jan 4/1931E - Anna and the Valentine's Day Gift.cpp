// Problem Link : https://codeforces.com/problemset/problem/1931/E

// Logic : (From Video)

// Final element >= 10^m means that the number of digits in the final element should be atleast (m + 1).
// Anna reverses, Sasha concatenates
// Note that the number of digits matter, the number itself doesn't matter!!!
// If only Sasha plays and Anna is absent, then Sasha will concatenate all the elements of the array as per optimal move.
// Anna should attempt to reduce the number of digits to increase her chances of winning.
// She can reduce the number of digits !! For example, she can take 100 and reverse it to make it 1. So, 2 digits lost in this case.
// If there are x number of trailing zeroes of a number, then if Anna reverses it, the x trailing zeroes are lost.
// Also, Anna will do a reversal operation only once on an element.
// So, Anna's strategy - Pick the number with most ending zeroes and reverse it. The number of lost digits is equal to the number of ending zeroes.
// Sasha should stop this strategy of Anna. As Anna has the first turn, Anna selects the element with largest number of ending zeroes.
// Then Sasha can select the number with 2nd most largest number of ending zeroes, and so-on.
// Also, the non-zero digits are never lost!!

// Code :

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int final_ele_digits = 0;
    vector<int> vec;
 
    for(auto& element : a){
        
        int ending_zeroes = 0, non_zero_dig = 0;
 
        //trailing zeroes
        while(element % 10 == 0){
            ending_zeroes++;
            element /= 10;
        }
 
        //non-zero digits
        while(element){
            non_zero_dig++;
            element /= 10;
        }
 
        final_ele_digits += non_zero_dig;
        vec.push_back(ending_zeroes);
    }
 
    sort(vec.begin(), vec.end(), greater<int>());
 
    for(int i = 1; i < vec.size(); i += 2){
        final_ele_digits += vec[i];
    }
 
    cout << (final_ele_digits >= m + 1 ? "Sasha" : "Anna") << "\n";
 
}

