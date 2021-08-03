class Solution
{
public:
    int titleToNumber(string title)
    {
        int no = 0;
        // iterate over the title
        for (int i = 0; i < title.size(); i++)
        {
            // find the value of each char i.e. A-> 1, B->2.......Z->26
            int value = title[i] - 'A' + 1;

            no += value * pow(26, title.size() - i - 1);
        }
        return no;
    }
};