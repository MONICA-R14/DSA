class Solution {
public:
    int myAtoi(string s) {
    long long num = 0;
    int flag = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == ' ' && flag == 0)
            continue;

        if (flag == 0 && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            flag = 1;
            continue;
        }

        if (flag != 0 && (s[i] == '-' || s[i] == '+'))
            break;

        if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            num = num * 10 + (s[i] - '0');

            // overflow check
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;
        }
        else
            break;
    }

    if (flag == 0)
        return 0;

    return sign * num;
}

};