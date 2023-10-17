# Create a vector containing the marks for each subject.
marks <- c(70, 95, 80, 74, 85)

# Call the barplot() function.
barplot(
  marks,
  main = "Comparing marks of 5 subjects",
  xlab = "Marks",
  ylab = "Subject",
  names.arg = c("English", "Science", "Math", "History", "Geography")
)
