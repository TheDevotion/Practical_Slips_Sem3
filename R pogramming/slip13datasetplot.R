# Consider the inbuilt iris dataset
# i) Create a variable “y” and attach to it the output attribute of the
#“iris” dataset.
# ii) Create a barplot to breakdown your output attribute.
# iii) Create a density plot matrix for each attribute by class value. 



#load iris dataset

data(iris)

# creating Y variable and attaching the output attribute "Species" to it

y <- iris$Species

#create barplot for "Species"

barplot(table(y), main = "Breakdown of Species", xlab = "Species", ylab = "Frequency")

#Creating density plot matrix for each attribute by class value

# Create density plots for each attribute by Species
attributes <- c("Sepal.Length", "Sepal.Width", "Petal.Length", "Petal.Width")

par(mfrow = c(2, 2))  # Set up a 2x2 grid for plots

lapply(attributes, function(attr) {
  for (species in unique(iris$Species)) {
    subset_data <- iris[iris$Species == species, ]
    density_data <- density(subset_data[[attr]])
    plot(density_data, main = paste(attr, "-", species))
  }
})