class Solution {

    private boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public int findTheLongestSubstring(String s) {
        int n = s.length(), mask = 0, res = 0;
        int[] index = new int[32];
        Arrays.fill(index, -1);
        index[0] = -1;

        Map<Character, Integer> position = new HashMap<>();
        position.put('a', 0);
        position.put('e', 1);
        position.put('i', 2);
        position.put('o', 3);
        position.put('u', 4);

        for (int i = 0; i < n; i++) {
            if (isVowel(s.charAt(i))) {
                mask ^= (1 << position.get(s.charAt(i)));
            }

            if (mask != 0 && index[mask] == -1) {
                index[mask] = i;
            }

            res = Math.max(res, i - index[mask]);
        }

        return res;
    }
}