#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Return final state of asteroids after collisions
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(int ast : asteroids){
        bool alive = true;
        while(alive && ast < 0 && !st.empty() && st.top() > 0){
            if(st.top() < -ast){ st.pop(); continue; }
            else if(st.top() == -ast){ st.pop(); }
            alive = false;
        }
        if(alive) st.push(ast);
    }

    vector<int> res(st.size());
    for(int i = st.size()-1; i >= 0; i--){
        res[i] = st.top(); st.pop();
    }
    return res;
}

int main(){
    vector<int> ast = {5, 10, -5};
    vector<int> res = asteroidCollision(ast);
    for(int x : res) cout << x << " ";
}
