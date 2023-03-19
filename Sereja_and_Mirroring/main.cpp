#include<iostream>

int reduce_till_equal(bool** , int, int);

int main() {
    int n, m;
    std::cin >> n >> m;

    bool **matrix;
    matrix = new bool *[n];

    for(int i = 0; i < n; i++){
        matrix[i] = new bool[m]; 
        for(int j = 0; j < m; j++){
            std::cin >> matrix[i][j];
        }
    }

    std::cout << reduce_till_equal(matrix, n, m) << std::endl;
}

int reduce_till_equal(bool** matrix, int max_rows_to_check, int max_columns) {
    if(max_rows_to_check == 1 || max_rows_to_check & 1) return max_rows_to_check;

    for(int row = 0; row < max_rows_to_check / 2; row++) {
        for(int column = 0; column < max_columns; column++) {
            if(matrix[row][column] != matrix[max_rows_to_check - row - 1][column]) return max_rows_to_check;
        }
    }

    return reduce_till_equal(matrix, max_rows_to_check / 2, max_columns);
}