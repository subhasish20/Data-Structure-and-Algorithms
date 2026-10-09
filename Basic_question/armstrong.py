number = int(input("Enter the number to chck armstrong :"))

pow  : int = 0;


original = number


while number > 0:
    remainder = number % 10
    pow = pow +  remainder ** 3
    number = number // 10


if pow == original:
    print("Given number is armstrong ")
else:
    print("Given number is not armstrong")
