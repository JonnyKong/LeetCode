/**
 * Use DFS to detect cycles in graph. If there are cycles in the graph, it
 * means that it is impossible to finish all courses.
 * 
 * Uses additional state in visited[] array.
 */

class Solution {

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        /* Construct adjacency list */
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < numCourses; ++i)
            graph.add(new ArrayList<>());
        for(int[] a : prerequisites)
            graph.get(a[0]).add(Integer.valueOf(a[1]));

        /* Search for cycles */
        /**
         * Search for cycle.
         * visited[i] = 0: Has not visited
         * visited[i] = 1: Executing DFS on its descendants
         * visited[i] = 2: Visited
         */
        int[] visited = new int[numCourses];
        for(int i = 0; i < numCourses; ++i){
            assert(visited[i] != 1);
            if(visited[i] == 2)
                continue;
            else if(!dfs(graph, visited, i))
                return false;
        }

        return true;
    }

    /* DFS starting from node v */
    private boolean dfs(final ArrayList<ArrayList<Integer>> graph, int[] visited, int root) {

        visited[root] = 1;

        for(Integer v : graph.get(root)) {
            if(visited[v] == 2)
                continue;
            else if(visited[v] == 1)
                return false;
            else if(!dfs(graph, visited, v))
                return false;
        }

        visited[root] = 2;
        return true;
    }
}