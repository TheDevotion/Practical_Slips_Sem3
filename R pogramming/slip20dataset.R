# Consider Weather dataset
# i) Selecting using the column number
# ii) Selecting using the column name
# iii) Make a scatter plot to compare Wind speed and temperature 

# Sample weather data with similar column names
weather_data <- data.frame(
  Temperature = c(20, 25, 30, 22, 18),
  Wind_Speed = c(5, 7, 10, 4, 6)
)

# i) Selecting using the column number
selected_data_by_number <- weather_data[, c(1, 2)]

# ii) Selecting using the column name
selected_data_by_name <- weather_data[, c("Temperature", "Wind_Speed")]

# iii) Make a scatter plot to compare Wind speed and temperature
plot(weather_data$Wind_Speed, weather_data$Temperature,
     xlab = "Wind Speed", ylab = "Temperature",
     main = "Scatter plot of Wind Speed vs Temperature")
