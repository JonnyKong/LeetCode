/**
 * BFS.
 */

class Solution {

    public int[][] updateMatrix(int[][] matrix) {

        boolean[][] visited = new boolean[matrix.length][matrix[0].length];
        int[][] result = new int[matrix.length][matrix[0].length];
        for(int i = 0; i < matrix.length; ++i) {
            for(int j = 0; j < matrix[0].length; ++j) {
                result[i][j] = Integer.MAX_VALUE;
            }
        }

        /* Two concurrent queues recording x and y coordinates */
        Queue<Integer> x_coord = new LinkedList<>();
        Queue<Integer> y_coord = new LinkedList<>();

        for(int i = 0; i < matrix.length; ++i) {
            for(int j = 0; j < matrix[0].length; ++j) {
                if(matrix[i][j] == 0) {
                    x_coord.add(i);
                    y_coord.add(j);
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;      /* BFS level */
        while(!x_coord.isEmpty()) {
            int size = x_coord.size();  /* Current BFS level size */
            for(int i = 0; i < size; ++i) {
                int x = x_coord.poll();
                int y = y_coord.poll();

                result[x][y] = level;

                if(x - 1 >= 0 && !visited[x - 1][y]) {
                    x_coord.add(x - 1);
                    y_coord.add(y);
                    visited[x - 1][y] = true;
                }
                if(x + 1 < matrix.length && !visited[x + 1][y]) {
                    x_coord.add(x + 1);
                    y_coord.add(y);
                    visited[x + 1][y] = true;
                }
                if(y - 1 >= 0 && !visited[x][y - 1]) {
                    x_coord.add(x);
                    y_coord.add(y - 1);
                    visited[x][y - 1] = true;
                }
                if(y + 1 < matrix[0].length && !visited[x][y + 1]) {
                    x_coord.add(x);
                    y_coord.add(y + 1);
                    visited[x][y + 1] = true;
                }
            }
            ++level;
        }

        return result;
    }
}