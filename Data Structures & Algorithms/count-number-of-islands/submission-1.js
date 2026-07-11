class Solution {
    /**
     * @param {character[][]} grid
     * @return {number}
     */
    numIslands(grid) {

        function markNodes(i, j) {
            if(i < 0 || i >= grid.length) return;
            if(j < 0 || j >= grid[0].length) return;
            if(grid[i][j] === "0") return;
            grid[i][j] = "0"

            markNodes(i+1, j);
            markNodes(i-1, j);
            markNodes(i, j+1);
            markNodes(i, j-1);
        }

        let count = 0;

        for(let i=0; i< grid.length; i++) {
            for(let j=0; j<grid[0].length; j++) {
                if(grid[i][j] === "1") {
                    count++;
                    markNodes(i, j);
                }
            }
        }

        return count;
    }
}
