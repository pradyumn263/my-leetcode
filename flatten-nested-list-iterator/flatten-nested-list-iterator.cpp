/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            if (nestedList[i].isInteger() || nestedList[i].getList().size() > 0) {
                st.push(nestedList[i]);
            }
        }
    }
    
    int next() {
        NestedInteger temp = st.top();
        st.pop();
        
        return temp.getInteger();
    }
    
    bool hasNext() {
        if (st.empty())
            return false;
        
        NestedInteger temp = st.top();
        if (temp.isInteger())
            return true;
        
        while(!st.empty() && !temp.isInteger()) {
            vector<NestedInteger> tempList = temp.getList();
            st.pop();
            
            for (int i = tempList.size() - 1; i >= 0; i--) {      
                if (tempList[i].isInteger() || tempList[i].getList().size() > 0) {
                    st.push(tempList[i]);
                }
            }
            
            if (!st.empty()) {
                temp = st.top();
            }
        }
        
        if (temp.isInteger())
            return true;
        
        if (st.empty())
            return false;
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */