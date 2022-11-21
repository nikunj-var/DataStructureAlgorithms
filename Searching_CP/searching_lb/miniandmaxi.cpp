// find middle element

class Solution
{
public:
    int middle(int A, int B, int C)
    {
        // code here//Position this line where user code will be pasted.
        int maxi = max(A, max(B, C));
        int mini = min(A, min(B, C));
        return (A + B + C - (mini + maxi));
    }
};