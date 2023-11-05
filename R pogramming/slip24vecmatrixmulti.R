# Create two vectors of different lengths
v1 <- c(1, 2, 3)
v2 <- c(4, 5, 6, 7)

# Convert vectors to matrices
mat1 <- matrix(v1, ncol = 1)  # Convert vector v1 to a column matrix
mat2 <- matrix(v2, ncol = 1)  # Convert vector v2 to a column matrix

# Perform matrix multiplication
result <- mat1 %*% t(mat2)  # Perform matrix multiplication

# Print the result of matrix multiplication
print("Result of matrix multiplication:")
print(result)


# 
# This script creates matrices from the vectors 
# and performs matrix multiplication using the 
# %*% operator in R. The %*% operator is used
# for matrix multiplication. This operation allows
# you to perform matrix multiplication even with 
# vectors of different lengths by properly aligning
# them as matrices.