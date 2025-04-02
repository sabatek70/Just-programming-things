import math

# Counts the digits of a maximum 13 digit number using only 1 variable

# Reading the input and cutting the number if it's too long
n = int(input("Number: "))
if len(str(n)) > 13:
    print("The number is too long, maximum digits: 13.\nCutting the number to 13 digits")
print("Sum of even digits of ", str(n)[0:13], end='')
n = float(str(n)[0:13])

# Adding the digits and saving them after the float point
while int(n) > 0:
    if int(n) % 10 % 2 == 0:
        n = n + ((int(n) % 10) * 0.001)
    n = int(n/10) + float(n%1)

# Fixing the floating point inaccuracy
if n%1 < 0.09: 
    n = round(n%1*1000) 
else:
    n = math.ceil(n%1*1000)

# Printing the result
print(" is", n, ".")