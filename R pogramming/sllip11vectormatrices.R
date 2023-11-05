# Write a script in R to create two vectors of different lengths and give these vectors as
# input to array and print addition and subtraction of those matrices. 


v1 <- c(1,2,3)
v2 <- c(4,5,6,7)

#creating arrays from vectors
arr1 <- array(v1,dim = c(3,1))   # Convert vector1 to a 3x1 array
arr2 <- array(v2,dim = c(4,1))  # Convert vector1 to a 4x1 array

#we can only add and subtract arrays with common length. therefore

len <- min(length(v1),length(v2))

#addition and subtraction (element wise)

add <- v1[1:len] + v2[1:len]
sub <- v1[1:len] - v2[1:len]


print("Matrix addition")
print(add)

print("Matrix Subtraction")
print(sub)