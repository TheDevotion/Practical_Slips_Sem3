#Write an R program to create a simple bar plot of five subject’s marks. 

#sub and marks

subject <- c("m","p","s","c","y")
marks <- c(20,50,80,10,66)

#barplot

barplot(marks, names.arg = subject, xlab="subject", ylab="marks", col="red", main="Marks of subject")