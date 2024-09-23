class Solution {

    private int recursion(String s, int idx, HashMap<String, Integer> mp, int[] dp) {
        if (idx == s.length()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        String curr = "";
        int currExtra = 0;
        int minExtra = s.length();

        for (int i = idx; i < s.length(); i++) {
            curr += s.charAt(i);
            currExtra = mp.containsKey(curr) ? 0 : curr.length();
            int nxtExtra = recursion(s, i + 1, mp, dp);
            int totalExtra = currExtra + nxtExtra;
            minExtra = Math.min(minExtra, totalExtra);
        }

        return dp[idx] = minExtra;
    }

    public int minExtraChar(String s, String[] dictionary) {

        int[] dp = new int[s.length()];

        for (int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }

        HashMap<String, Integer> mp = new HashMap<>();
        
        for (String word : dictionary) {
            mp.put(word, mp.getOrDefault(word, 0) + 1);
        }

        return recursion(s, 0, mp, dp);
    }
}