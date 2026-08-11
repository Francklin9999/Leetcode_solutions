class Solution {
unordered_map<string, string> map;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto curr = "http://tinyurl.com/" + std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
        map.insert({curr, longUrl});
        return curr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));