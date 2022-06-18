// Ninjas Training
// venice 7
/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform
any one of these three activities. (Running, Fighting Practice or Learning New
Moves). Each activity has some merit points on each day. As Ninja has to improve
all his skills, he can’t do the same activity in two consecutive days. Can you
help Ninja find out the maximum merit points Ninja can earn? You are given a 2D
array of size N*3 ‘POINTS’ with the points corresponding to each day and
activity. Your task is to calculate the maximum number of merit points that
Ninja can earn.

Sample Input 1:
2
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90

Sample Output 1:
11
210

Explanation Of Sample Input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points.
On the second day, Ninja will do running and earn 3 merit points.
On the third day, Ninja will do fighting and earn 3 merit points.
The total merit point is 11 which is the maximum.
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points.
On the second day, Ninja will do fighting and earn 50 merit points.
On the third day, Ninja will learn new moves and earn 90 merit points.
The total merit point is 210 which is the maximum.
Hence, the answer is 210.
 */

//* Recursion
int nt(int day, int last, vector<vector<int>> &points) {
    int maxPoint = 0;
    if (day == 0) {
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxPoint = max(maxPoint, points[day][task]);
            }
        }
        return maxPoint;
    }
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + nt(day - 1, task, points);
            maxPoint = max(maxPoint, point);
        }
    }
    return maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    return nt(n - 1, 3, points);
}

//* Recursion + Memoization
int nt(int day, int last, vector<vector<int>> &points,
       vector<vector<int>> &dp) {
    int maxPoint = 0;

    if (dp[day][last] != -1) {
        return dp[day][last];
    }

    if (day == 0) {
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxPoint = max(maxPoint, points[day][task]);
            }
        }
        return maxPoint;
    }
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + nt(day - 1, task, points, dp);
            maxPoint = max(maxPoint, point);
        }
    }
    return dp[day][last] = maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return nt(n - 1, 3, points, dp);
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // base case
    /*
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    */
    // above base case can also be written as
    for (int last = 0; last <= 3; last++) {
        int maxPoint = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxPoint = max(maxPoint, points[0][task]);
            }
        }
        dp[0][last] = maxPoint;
    }

    for (int day = 1; day < n; day++) {
        for (int last = 0; last <= 3; last++) {
            int maxPoint = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    maxPoint = max(maxPoint, point);
                }
            }
            dp[day][last] = maxPoint;
        }
    }
    return dp[n - 1][3];
}

// ? Tabulation + Space Optimization
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));
    vector<int> prevDayTaskPoints(4, 0);
    //     base case
    //     prevDayTaskPoints[0] = max(points[0][1],points[0][2]);
    //     prevDayTaskPoints[1] = max(points[0][0],points[0][2]);
    //     prevDayTaskPoints[2] = max(points[0][0],points[0][1]);
    //     prevDayTaskPoints[3] =
    //     max(points[0][0],max(points[0][1],points[0][2]));
    // above base case can also be written as
    for (int last = 0; last <= 3; last++) {
        int maxPoint = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxPoint = max(maxPoint, points[0][task]);
            }
        }
        prevDayTaskPoints[last] = maxPoint;
    }

    for (int day = 1; day < n; day++) {
        vector<int> currDayTaskPoints(4, 0);
        for (int last = 0; last <= 3; last++) {
            int maxPoint = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prevDayTaskPoints[task];
                    maxPoint = max(maxPoint, point);
                }
            }
            currDayTaskPoints[last] = maxPoint;
        }
        prevDayTaskPoints = currDayTaskPoints;
    }
    return prevDayTaskPoints[3];
}