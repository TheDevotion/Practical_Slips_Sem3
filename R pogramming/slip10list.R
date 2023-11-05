# Write a script in R to create a list of cities and perform the following
# 1) Give names to the elements in the list.
# 2) Add an element at the end of the list.
# 3) Remove the last element.
# 4) Update the 3rd Element



cities <- list("New York", "London", "Paris", "Tokyo")

names(cities) <- c("City1", "City2", "City3", "City4")



#add element at the end of list

cities[["City5"]] <- "Sydney"

print(cities)

# remove last element
cities <- cities[-length(cities)]
print("After removing last:")

print(cities)

#Update the 3rd element

cities[["City3"]] <- "Berlin"

print("After updating 3rd")
print(cities)
 


