#Write an R program to sort a Vector in ascending and descending order.

v1 <- c(1, 4, 2, 7, 2, 5, 8,2)

ascending <- sort(v1)
descending <- sort(v1,decreasing=TRUE)

cat(ascending)
cat("\n") %>% 
cat(descending)