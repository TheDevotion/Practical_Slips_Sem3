# Write an R program to create three vectors a,b,c with 3 integers. Combine the three
# vectors to become a 3×3 matrix where each column represents a vector. Print the
# content of the matrix. 


#initialize an empty matrix to store user input

m1 <- matrix(NA, nrow=3, ncol=3)

#loop to take input for each vector

for(i in 1:3) {
  input <- readline(paste("Enter 3 int for vec ",i," (separated by space): "))
  m1[,i] <- as.numeric(unlist(strsplit(input," ")))
}

print("matrix is: ")

print(m1)






#alternate

# # Create three vectors with 3 integers each
# a <- c(1, 2, 3)
# b <- c(4, 5, 6)
# c <- c(7, 8, 9)
# 
# # Combine the three vectors into a 3x3 matrix
# combined_matrix <- matrix(c(a, b, c), nrow = 3, byrow = FALSE)
# 
# # Print the content of the matrix
# print(combined_matrix)