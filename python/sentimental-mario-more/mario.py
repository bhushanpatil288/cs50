# checking if user enter values are valid?
valid = False
while (valid == False):
    try:
        height = int(input("Height: "))
        while (height > 8 or height < 1):
            print("Please try again!")
            height = int(input("Height: "))

        for i in range(1, height+1):
            if (i != height):
                print(" " * (height-i), end="")
            print("#" * i, end="")
            print(" " * 2, end="")
            print("#" * i, end="")
            print()
        # stops the loop
        valid = True
    except ValueError:  # user entered invalid number
        print("Only numeric values are allowed")
        # keeps loop running
        valid = False
