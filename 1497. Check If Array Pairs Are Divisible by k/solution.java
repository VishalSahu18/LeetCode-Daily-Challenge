class Solution {
    public boolean canArrange(int[] arr, int k) {

        HashMap<Integer, Integer> count = new HashMap<>();

        for (int x : arr) {
            int remainder = ((x % k) + k) % k;
            count.put(remainder, count.getOrDefault(remainder, 0) + 1);
        }


        for (int key : count.keySet()) {

            int freq = count.get(key);

            if (key == 0) {
                if ((freq & 1) != 0) {
                    return false;
                }
            }else {
                int complementFreq = count.getOrDefault(k - key, 0);
                if (freq != complementFreq) {
                    return false;
                }
            }
        }

        return true;

    }
}