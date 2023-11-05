# Write a script in R to create two vectors of different lengths and give these vectors as
# input to array and print second row of second matrix of the array


# Creating two vectors of different lengths
v1 <- c(1, 2, 3)
v2 <- c(4, 5, 6, 7)

# Combine vectors into a single array with two rows
combined_array <- rbind(v1, v2)

# Accessing the second row of the combined array (second matrix)
second_row_second_matrix <- combined_array[2, ]

# Print the second row of the second matrix of the array
print("Second row of the second matrix of the array:")
print(second_row_second_matrix)