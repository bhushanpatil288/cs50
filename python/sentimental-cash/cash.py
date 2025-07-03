userInput = -1
while (userInput < 0):
    try:
        userInput = float(input("Change: "))
    except ValueError:
        print("please enter valid number!")
        userInput = float(input("Change: "))


change = 0
cents = round(userInput * 100)

while cents != 0:
    if cents >= 25:
        cents -= 25
        change += 1
    elif cents >= 10:
        cents -= 10
        change += 1
    elif cents >= 5:
        cents -= 5
        change += 1
    else:
        cents -= 1
        change += 1

print(change)
