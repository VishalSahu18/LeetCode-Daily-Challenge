class Solution {
    
    private void storeString(Map<String, Integer> count, String s) {
        String[] words = s.split(" "); 
        for (String word : words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
    }

    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> count = new HashMap<>();
        
        storeString(count, s1);
        storeString(count, s2);

        List<String> uncommonWords = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : count.entrySet()) {
            if (entry.getValue() == 1) {
                uncommonWords.add(entry.getKey());
            }
        }

        return uncommonWords.toArray(new String[0]);
    }
}