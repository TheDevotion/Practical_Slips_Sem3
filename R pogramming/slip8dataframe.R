#Write an R program to create a data frame using two given vectors and display the
#duplicated elements and unique rows of the said data frame. 

v1 <- c("A","B", "C", "D","A","E")
v2 <- c(1, 2, 3, 4, 1, 5)


myData <- data.frame(column1 = v1, column2 = v2)

print(myData)


#duplicate

duplicated_elements <- myData[duplicated(myData) | duplicated(myData, fromLast = TRUE),]

print("Duplicated elements")
print(duplicated_elements)


#unique

unique_rows <- myData[!duplicated(myData) & !duplicated(myData, fromlast = TRUE),]

print("Unique")
print(unique_rows)
