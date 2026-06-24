class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];

        for (char letter : s) {
            arr[static_cast<int>(letter) - static_cast<int>('a')]++;
        }

        for (char letter : t) {
            arr[static_cast<int>(letter) - static_cast<int>('a')]--;
        }

        for (int i = 0; i < 26; i++) {
            if(arr[i] != 0) return false;
        }

        return true;
    }
};