class Solution {
    public boolean checkInclusion(String s1, String s2) {
       int n1 = s1.length(), n2 = s2.length(), l = 0, r = 0;
       int[] count = new int[26];

       for (char c : s1.toCharArray()) {
            count[c - 'a']++;
        }

        while (r < n2) {
            count[s2.charAt(r) - 'a']--;
            n1--;

            while (count[s2.charAt(r) - 'a'] < 0) {
                count[s2.charAt(l++) - 'a']++;
                n1++;
            }

            if (n1 == 0)
                return true;
            r++;
        }

        return false;
    }
}