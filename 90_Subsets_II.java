class Solution {

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        /* Get number of occurrence of each element */
        ArrayList<Integer> vocab = new ArrayList<>();
        ArrayList<Integer> times = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; ++i) {
            if(i == 0 || nums[i] != vocab.get(vocab.size() - 1)) {
                vocab.add(Integer.valueOf(nums[i]));
                times.add(Integer.valueOf(1));
            } else {
                times.set(times.size() - 1, times.get(times.size() - 1) + 1);
            }
        }

        ArrayList<List<Integer>> result = new ArrayList<>();
        ArrayList<Integer> current = new ArrayList<>();
        dfs(result, vocab, times, current, 0);

        return result;
    }

    private void dfs(List<List<Integer>> result, final List<Integer> vocab,
                     final List<Integer> times, ArrayList<Integer> current, int index) {

        /* Termination */
        if(vocab.size() == index) {
            result.add(new ArrayList<>(current));
            return;
        }

        /* DFS */
        dfs(result, vocab, times, current, index + 1);
        for(int i = 0; i < times.get(index); ++i) {
            current.add(vocab.get(index));
            dfs(result, vocab, times, current, index + 1);
        }

        /* Current should stay same after returning */
        for(int i = 0; i < times.get(index); ++i) {
            current.remove(current.size() - 1);
        }
    }


}