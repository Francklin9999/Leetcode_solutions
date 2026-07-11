class Solution {
public:
    int reverse(int x) {
        std::string num = std::to_string(x);
        std::size_t l{};
        std::size_t r{num.size() - 1};

        if (num.at(l) == '-') l++;

        while (l < r) {
            swap(num.at(l), num.at(r));
            l++;
            r--;
        }

        try {
            return std::stoi(num);
        } catch (const std::out_of_range& r) {
            return 0;
        }

    }
};