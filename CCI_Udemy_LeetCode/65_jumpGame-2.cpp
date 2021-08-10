class Solution
{
public:
    int jump(vector<int> &A)
    {
        int n = A.size();
        if (n == 1)
            return 0;
        if (A[0] == 0)
            return -1;

        int ladder = A[0]; // next biggest ladder which we can take
        int stairs = A[0]; // How many steps the ladder contains // current ladder
        int jump = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jump; // if we reach at the end

            if (i + A[i] > ladder)
            {
                ladder = i + A[i];
            }
            stairs--; // traversing current ladder
            // if current ladder finishesh make a jump
            if (stairs == 0)
            {
                jump++;
                stairs = ladder - i;
            }
        }
        return -1;
    }
};