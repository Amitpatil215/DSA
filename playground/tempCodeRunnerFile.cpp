if (index1 == 0 && index2 == 0) {
            //     if (s1[index1] == s2[index2]) {
            //         dp[index1][index2] = 1;
            //     }
            // } else {
            //     // match
            //     if (s1[index1] == s2[index2]) {
            //         int one = 0;
            //         if (index1 > 0 && index2 > 0)
            //             one = dp[index1 - 1] + dp[index2 - 1];
            //         dp[index1][index2] = 1 + one;
            //     } else {
            //         // do not match
            //         int one = 0;
            //         int two = 0;
            //         if (index1 > 0) one = dp[index1 - 1] + dp[index2];
            //         if (index2 > 0) two = dp[index1] + dp[index2 - 1];
            //         dp[index1][index2] = 0 + max(one, two);
            //     }