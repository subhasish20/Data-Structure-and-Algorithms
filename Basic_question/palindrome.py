number = int(input("Enter the number to chck palindrome :"))

reverse : int = 0;


original = number


while number > 0 :
    remainder = number % 10
    reverse = reverse * 10 + remainder
    number = number // 10

if reverse == original:
    print("Given number is palindrome")
else:
    print("Given number is not palindrome")
