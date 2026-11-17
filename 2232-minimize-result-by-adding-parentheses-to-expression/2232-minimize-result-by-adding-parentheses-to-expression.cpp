class Solution {
public:
    string minimizeResult(string expression) {
        int plus = std::find(expression.begin(), expression.end(), '+') - expression.begin();

        int mn{INT_MAX};
        string res{};

        for (int i = 0; i < plus; ++i) {
            for (int j = plus + 2; j <= expression.size(); ++j) {
                string a = expression.substr(0, i);
                string b = expression.substr(i, plus - i);
                string c = expression.substr(plus + 1, j - plus - 1);
                string d = expression.substr(j);

                int A = a.empty() ? 1 : stoi(a);
                int B = b.empty() ? 1 : stoi(b);
                int C = c.empty() ? 1 : stoi(c);
                int D = d.empty() ? 1 : stoi(d);

                int curr = A * (B + C) * D;

                if (curr < mn) {
                    mn = curr;
                    res = a + '(' + b + '+' + c + ')' + d;
                } 
            }
        }

        return res;
    }
};