    #include <vector>
    #include <iostream>
    #include <stack>

    using namespace std;
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int size=popped.size();
        int j=0;
        for(int i=0;i<size;i++){
            if(st.size() && st.top()==popped[i]){
                st.pop();
                continue;
            }
            while(st.size()==0 ||(j<size && st.top()!=popped[i])){
                st.push(pushed[j++]);
            }
            if(st.top()!=popped[i])
                return false;
            st.pop();
        }
        return true;
    }