#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Calculate span of stock prices
vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // stores indices

    for(int i=0;i<n;i++){
        while(!st.empty() && prices[i] >= prices[st.top()]) st.pop();
        span[i] = st.empty() ? (i+1) : (i - st.top());
        st.push(i);
    }
    return span;
}

int main(){
    vector<int> prices = {100,80,60,70,60,75,85};
    vector<int> span = calculateSpan(prices);
    for(int x: span) cout << x << " ";
}
