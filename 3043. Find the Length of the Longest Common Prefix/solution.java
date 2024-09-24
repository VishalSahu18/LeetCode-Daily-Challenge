class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {

        HashSet<String> hs = new HashSet<>();
        int n1 = arr1.length, n2 = arr2.length, mx = 0;

       
        for (int i = 0; i < n1; i++) {
            String curr = "";
            String str = Integer.toString(arr1[i]);
            for (char x : str.toCharArray()) {
                curr += x;
                hs.add(curr);
            }
        }

        
        for (int i = 0; i < n2; i++) {
            String curr = "";
            String str = Integer.toString(arr2[i]);
            for (char x : str.toCharArray()) {
                curr += x;
                if (hs.contains(curr)) {
                    mx = Math.max(mx, curr.length());
                }
            }
        }

        return mx;
    }
}