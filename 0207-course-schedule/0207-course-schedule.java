class Solution {
    HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
    HashSet<Integer> visited = new HashSet<>();
    HashSet<Integer> path = new HashSet<>();

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        for (int i = 0; i < prerequisites.length; i++) {
            map.put(prerequisites[i][0], map.getOrDefault(prerequisites[i][0], new ArrayList<Integer>()));
            map.get(prerequisites[i][0]).add(prerequisites[i][1]);
        }

        for (var c : map.entrySet()) {
            if (!dfs(c.getKey())) return false;
        }

        return true;
    }

    private boolean dfs(int a) {
        if (path.contains(a)) return false;
        if (visited.contains(a)) return true;

        visited.add(a);
        path.add(a);

        if (!map.containsKey(a)) {
            path.remove(a);
            return true;
        }
        var curr = map.get(a);

        for (int num : curr) {
            if (!dfs(num)) return false;
        }

        path.remove(a);
        return true;
    }
}