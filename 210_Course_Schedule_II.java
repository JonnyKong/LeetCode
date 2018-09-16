/**
 * Toposort: Get postorder of DFS on reverse graph.
 */

class Solution {

    private ArrayList<Integer> pathReverse;

    public int[] findOrder(int numCourses, int[][] prerequisites) {

        /* Construct adjacency list (in reverse) */
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < numCourses; ++i)
            graph.add(new ArrayList<>());
        for(int[] a : prerequisites)
            graph.get(a[0]).add(Integer.valueOf(a[1]));
        pathReverse = new ArrayList<>();

        /**
         * Mark visited nodes and detect cycles.
         * visited[i] = 0: Has not visited
         * visited[i] = 1: Executing DFS on its descendants
         * visited[i] = 2: Visited
         */
        int[] visited = new int[numCourses];

        /* Toposort */
        for(int i = 0; i < numCourses; ++i) {
            if(visited[i] == 2)
                continue;
            else if(!dfs(graph, visited, i))    /* Cycle detected */
                return new int[0];
        }

        int[] result = new int[numCourses];
        for(int i = 0; i < numCourses; ++i)
            result[i] = pathReverse.get(i);

        return result;
    }

    private boolean dfs(ArrayList<ArrayList<Integer>> graph, int[] visited, int root) {

        visited[root] = 1;

        for(int v : graph.get(root)) {

            if(visited[v] == 1)
                return false;
            else if(visited[v] == 2)
                continue;
            else if(!dfs(graph, visited, v))
                return false;
        }

        pathReverse.add(root);
        visited[root] = 2;
        return true;
    }
}