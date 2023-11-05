#Write an R program to create a Dataframes which contain details of 5 employees and
#display the details in ascending order. 

#creating a dataframe

emp_data <- data.frame(
  empId = c(1,5,3,2,4),
  empName = c("a", "b", "c", "d","e"),
  salary =c(5000,2000,5000,3000,67000)
)

print("Before sorting")
print(emp_data)

#sorting

sorted_emp_data <- emp_data[order(emp_data$empId),]

print("sorted data\n")
print(sorted_emp_data)