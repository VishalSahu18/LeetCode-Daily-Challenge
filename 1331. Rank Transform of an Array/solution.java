class Solution {
    public int[] arrayRankTransform(int[] arr) {

        int n = arr.length;
        HashMap<Integer,Integer>hm = new HashMap<>();
        int nums[] = new int[n];

        for(int i=0;i<n;i++)
            nums[i] = arr[i];

        Arrays.sort(nums);
        int rank = 1;

        for(int i=0;i<n;i++){
            if(!hm.containsKey(nums[i])){
                hm.put(nums[i],rank);
                rank++;
            }
        }

        for(int i=0;i<n;i++)
            nums[i] = hm.get(arr[i]);

        return nums;
        
    }
}