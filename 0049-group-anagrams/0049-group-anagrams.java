class Solution {
    public String sortString(String s)
    {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);
        return sorted;
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> sortedToOriginal = new HashMap<String, List<String>>();

        for(int i=0; i<strs.length; i++) {
            String sorted = sortString(strs[i]);
            if (!sortedToOriginal.containsKey(sorted)) {
                sortedToOriginal.put(sorted, new ArrayList<String>());
            }
            sortedToOriginal.get(sorted).add(strs[i]);
        }
        
        List<List<String>> res = new ArrayList<List<String>>();

        for(String key : sortedToOriginal.keySet()) {
            res.add(sortedToOriginal.get(key));
        }

        return res;
    }
}