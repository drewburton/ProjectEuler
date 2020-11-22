public class Grid {
    private long[][] grid;    

    public Grid(int size) {
        size += 1;
        grid = new long[size][size];
        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {
                grid[row][column] = 0;
            }
        }
    }

    public void printGrid() {
        for (int row = 0; row < grid.length; row++) {
            for (int column = 0; column < grid.length; column++) {
                System.out.print(grid[row][column] + " ");
            }
            System.out.println();
        }
    }

    public long calculatePaths() {
        // top left = 1; iterate on diags, count all around it
        grid[0][0] = 1;
        for (int row = 0; row < grid.length; row++) {
            for (int column = 0; column < grid.length; column++) {
                if (row == 0 && column == 0) 
                    continue;
                grid[row][column] = addSurroudning(row, column);
            }
        }
        return grid[grid.length - 1][grid.length - 1];
    }

    private long addSurroudning(int row, int column) {
        long result = 0;
        if (row - 1 >= 0) {
            result += grid[row - 1][column];
        }
        if (column - 1 >= 0) {
            result += grid[row][column - 1];
        }
        if (column + 1 < grid.length) {
            result += grid[row][column + 1];
        }
        if (row + 1 < grid.length) {
            result += grid[row + 1][column];
        }
        return result;
    }
}
