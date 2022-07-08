vector<int> nextGreaterElement(vector<int> vec) {
    // next greater elemets
    vector<int> res(vec.size(),-1);
    stack<int> st;
    for(int i = 0; i < vec.size(); i++) {
        while(!st.empty() && vec[st.top()] < vec[i]) {
            res[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
