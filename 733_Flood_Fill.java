/**
 * Trivial DFS.
 */

class Solution {

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {

        int[][] visited = new int[image.length][image[0].length];
        int oldColor = image[sr][sc];

        dfs(image, visited, sr, sc, oldColor, newColor);

        return image;

    }

    private void dfs(int[][] image, int[][] visited, int m, int n, final int oldColor, final int newColor) {

        visited[m][n] = 1;

        if(image[m][n] != oldColor)
            return;
        else
            image[m][n] = newColor;

        if(m - 1 >= 0 && visited[m - 1][n] == 0)
            dfs(image, visited, m - 1, n, oldColor, newColor);
        if(m + 1 < image.length && visited[m + 1][n] == 0)
            dfs(image, visited, m + 1, n, oldColor, newColor);
        if(n - 1 >= 0 && visited[m][n - 1] == 0)
            dfs(image, visited, m, n - 1, oldColor, newColor);
        if(n + 1 < image[0].length && visited[m][n + 1] == 0)
            dfs(image, visited, m, n + 1, oldColor, newColor);

    }

}