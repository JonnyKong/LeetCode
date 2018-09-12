/**
 * This solution uses BFS, without explicitly constructing a graph.
 * 
 * A queue is maintained for BFS, and connecting edges are lazily searched when 
 * visiting this node.
 * 
 * Length of path is maintained by a single variable and a double-loop.
 */

class Solution {

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        int level = 0;          /* BFS level */

        /* Build set for fast look-up */
        Set<String> wordSet = new HashSet<>(wordList);

        /* Uses double loop to increment level */
        while(!q.isEmpty()) {

            int size = q.size();
            for(int i = 0; i < size; ++i) {
                String cur = q.poll();

                /* Reached BFS destination */
                if(cur.equals(endWord))
                    return level + 1;

                /* Search for connecting nodes */
                for(int j = 0; j < cur.length(); ++j) {
                    char[] cur_array = cur.toCharArray();
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        cur_array[j] = ch;
                        String word = new String(cur_array);
                        if(wordSet.contains(word)) {
                            q.add(word);
                            wordSet.remove(word);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
}