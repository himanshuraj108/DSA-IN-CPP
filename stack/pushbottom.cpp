#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> &st)
{
    stack<int> temp;
    while (st.size() > 0)
    {
        cout << st.top() << " "; // starting from 50 40 30 20 10 70
        temp.push(st.top());
        st.pop();
    }

    cout << endl;
    while (temp.size() > 0)
    {

        st.push(temp.top());
        cout << st.top() << " "; // starting from 70 10 20 30 40 50
        temp.pop();
    }
}

int main()
{

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    stack<int> temp;

    while (st.size() > 0)
    {
        temp.push(st.top());
        st.pop();
    }

    int value;
    cin >> value;
    while (st.empty())
    {
        st.push(value);
    }

    while (temp.size() > 0)
    {
        st.push(temp.top());
        temp.pop();
    }

    print(st);
}