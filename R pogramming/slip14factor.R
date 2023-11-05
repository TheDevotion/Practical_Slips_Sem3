#Write an R program to concatenate two given factor in a single factor and display in
#descending order.

fact1 <- factor(c("A", "B", "C", "D"))
fact2 <- factor(c("E", "F", "G", "H"))


combine_factor <- factor(c(fact1,fact2))

descFactor <- combine_factor[order(combine_factor, decreasing = TRUE)]


print('combined factor in decreasing order')
print(descFactor)