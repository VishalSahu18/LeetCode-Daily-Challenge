class Solution {
    public String largestNumber(int[] nums) {

        int n = nums.length;
        String[] store = new String[n];

        for (int i = 0; i < n; i++) {
            store[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(store, (a, b) -> (b + a).compareTo(a + b));

        if (store[0].equals("0")) {
            return "0";
        }

        StringBuilder ans = new StringBuilder();
        
        for (String s : store) {
            ans.append(s);
        }

        return ans.toString();
    }
}