#Write an R program to change the first level of a factor with another level of a given
#factor.

#taking a factor from user.

userInput <- character(0)
num <- as.integer(readline(prompt = " Enter the number of factor values you want: "))


for(i in 1:num) {
  value <- readline(prompt = paste("Enter value ",i,":"))
  userInput <- c(userInput,value)
}


#converting it into factor

fact <- as.factor(userInput)

print("Factor before change:")
print(fact)

#define new levels

new_levels <- levels(fact)
new_levels[1] <- "grapes"

#assign the updated leverls to the factor

levels(fact) <- new_levels

print("Factor after changing the first level:")
print(fact)

#output:

# 
#   [1] "Factor before change:"
# [1] apple  banana orange apple  banana
# Levels: apple banana orange
# [1] "Factor after changing the first level:"
# [1] grapes banana orange grapes banana
# Levels: grapes banana orange
#

