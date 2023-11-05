#Write an R program to convert a given matrix to a list and print list in ascending
#order.


# Create a sample matrix
mat <- matrix(c(4, 2, 6, 1, 5, 3), nrow = 2)  # Example matrix

# Convert the matrix to a list
mat_list <- as.list(mat)

# Flatten the list to sort the elements
sorted_list <- sort(unlist(mat_list))

# Print the sorted list
print("Sorted list:")
print(sorted_list)