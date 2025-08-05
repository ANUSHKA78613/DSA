class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}
    
public:
    StockSpanner() {
        // No initialization required
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
