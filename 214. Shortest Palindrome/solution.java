class Solution {

    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String tmp = s + "#" + rev;

        int n = tmp.length();
        
        // building lookup table (lps[] longest proper suffix) using KMP algorithm
        int[] lps = new int[n];
        int index = 0;
        lps[0] = 0;

        for (int i = 1; i < n; i++) {
            if (tmp.charAt(i) == tmp.charAt(index)) {
                lps[i] = lps[i - 1] + 1;
                index++;
            } else {
                index = lps[i - 1];

                while (index > 0 && tmp.charAt(index) != tmp.charAt(i)) {
                    index = lps[index - 1];
                }

                if (tmp.charAt(index) == tmp.charAt(i)) {
                    index++;
                }

                lps[i] = index;
            }
        }

        int pos = lps[n - 1];
        String res = s.substring(pos);
        res = new StringBuilder(res).reverse().toString();

        return res + s;
    }
}
