import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Load dataset
dataset = pd.read_csv('Salary_Data.csv')  # FIX: missing opening quote

# Feature selection (independent variable X and dependent variable y)
x = dataset.iloc[:, :-1]  # Years of experience (Independent variable)
y = dataset.iloc[:, -1]   # Salary (Dependent variable)

# Split the dataset into training and testing sets (80% training, 20% testing)
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.20, random_state=0)

# Reshape x_train and x_test into 2D arrays if they are single feature columns
x_train = x_train.values.reshape(-1, 1)
x_test = x_test.values.reshape(-1, 1)

# Fit the Linear Regression model to the training set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(x_train, y_train)

# Predicting the results for the test set
y_pred = regressor.predict(x_test)

# Visualizing the Training set results
plt.scatter(x_train, y_train, color='red')
plt.plot(x_train, regressor.predict(x_train), color='blue')
plt.title('Salary vs Experience (Training set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

# Visualizing the Test set results
plt.scatter(x_test, y_test, color='red')
plt.plot(x_train, regressor.predict(x_train), color='blue')
plt.title('Salary vs Experience (Test set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

# Output the coefficients of the linear model
print(f"Intercept: {regressor.intercept_}")
print(f"Coefficient: {regressor.coef_}")

bias = regressor.score(x_train, y_train)
print(bias)

variance = regressor.score(x_test, y_test)
print(variance)

# Compare predicted and actual salaries from the test set
comparison = pd.DataFrame({'Actual': y_test, 'Predicted': y_pred})
print(comparison)

# STATISTICS FOR MACHINE LEARNING
dataset.mean()
dataset['Salary'].mean()
dataset.median()
dataset['Salary'].mode()
dataset.describe()
dataset.var()
dataset.std()
dataset.corr()

# FIX: All regression metrics must use the same y_test and y_pred (no slicing y)
y_mean = np.mean(y_test)

# SSR (Sum of Squares due to Regression)
SSR = np.sum((y_pred - y_mean) ** 2)
print("SSR:", SSR)

# SSE (Sum of Squares due to Error)
SSE = np.sum((y_test - y_pred) ** 2)  # FIX: removed incorrect slice y=y[0:6]
print("SSE:", SSE)

# SST (Total Sum of Squares)
SST = np.sum((y_test - y_mean) ** 2)  # FIX: use y_test not full dataset
print("SST:", SST)

# R² (FIX: correct formula is 1 - SSE/SST, not 1 - SSR/SST)
r_square = 1 - SSE / SST
print("R²:", r_square)

bias = regressor.score(x_train, y_train)
print("Bias (Train R²):", bias)

variance = regressor.score(x_test, y_test)
print("Variance (Test R²):", variance)

# Save the trained model to disk
import pickle
with open('linear_regression_model.pkl', 'wb') as file:
    pickle.dump(regressor, file)

print("Model has been pickled and saved as linear_regression_model.pkl")

import os
print(os.path.exists('linear_regression_model.pkl'))
