class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            int d = sum % 10;
            carry = sum / 10;
            ans = to_string(d) + ans;
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            int d = sum % 10;
            carry = sum / 10;
            ans = to_string(d) + ans;
            i--;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            int d = sum % 10;
            carry = sum / 10;
            ans = to_string(d) + ans;
            j--;
        }
        if (carry) {
            ans = to_string(carry) + ans;
        }
        return ans;
    }
};