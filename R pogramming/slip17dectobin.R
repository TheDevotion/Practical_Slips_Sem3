# Write an R Program to calculate Decimal into binary of a given number. 

#function to convert decimal to binary

dec_to_bi <- function (dec) {
  
  bin <- intToBits(dec)
  
  #imp
  bin <- paste(rev(bin), collapse = "")
  
  bin <- substring(bin,1,nchar(bin))
  
  return(bin)
}

dec <- as.integer(readline(prompt = "Give a number: "))

binary <- dec_to_bi(dec)

cat("binary of ", dec ," is:\n")

print(binary)
