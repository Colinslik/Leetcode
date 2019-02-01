void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j;
    for(i=0;i<matrixRowSize;i++)
    {
        for(j=i+1;j<matrixColSize;j++)
        {
            matrix[i][j] = matrix[i][j]^matrix[j][i];
            matrix[j][i] = matrix[i][j]^matrix[j][i];
            matrix[i][j] = matrix[i][j]^matrix[j][i];
        }
    }
    for(i=0;i<matrixRowSize;i++)
    {
        for(j=0;j<(matrixColSize/2);j++)
        {
            matrix[i][j] = matrix[i][j]^matrix[i][matrixColSize-1-j];
            matrix[i][matrixColSize-1-j] = matrix[i][j]^matrix[i][matrixColSize-1-j];
            matrix[i][j] = matrix[i][j]^matrix[i][matrixColSize-1-j];
        }
    }
}
