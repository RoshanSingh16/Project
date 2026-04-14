import streamlit as st
import numpy as np
import pickle

# Load the trained model
with open('linear_regression_model.pkl', 'rb') as file:
    regressor = pickle.load(file)

st.title('Salary Predictor')
st.write('Predict salary based on years of experience using a Linear Regression model.')

years = st.number_input('Enter Years of Experience:', min_value=0.0, max_value=50.0, step=0.5)

if st.button('Predict Salary'):
    prediction = regressor.predict(np.array([[years]]))
    st.success(f'Predicted Salary: ₹{prediction[0]:,.2f}')
