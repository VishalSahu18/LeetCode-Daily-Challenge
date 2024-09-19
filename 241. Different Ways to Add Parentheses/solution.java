class Solution {

    Map<String, List<Integer>> map = new HashMap<>();
    public List<Integer> recursion(String curr) {
        if (map.containsKey(curr)) {
            return map.get(curr);
        }

        List<Integer> ans = new ArrayList<>();
        int n = curr.length();

        for (int i = 0; i < n; i++) {
            char c = curr.charAt(i);

            if (c == '-' || c == '*' || c == '+') {
                List<Integer> a = recursion(curr.substring(0, i));
                List<Integer> b = recursion(curr.substring(i + 1));

                for (int x : a) {
                    for (int y : b) {
                        int z = 0;
                        if (c == '-') {
                            z = x - y;
                        } else if (c == '+') {
                            z = x + y;
                        } else {
                            z = x * y;
                        }
                        ans.add(z);
                    }
                }
            }
        }

        if (ans.isEmpty()) {
            ans.add(Integer.parseInt(curr));
        }

        map.put(curr, ans);
        return ans;
    }
    
    public List<Integer> diffWaysToCompute(String expression) {
        return recursion(expression);
    }
}