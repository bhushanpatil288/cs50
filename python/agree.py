# s = input("Do you agree?: ").lower()

# if s == 'y':
#     print("Agreed.")
# elif s == 'n':
#     print("Declined.")



# VERSION 2

s = input("Do you agree?: ")

if s[0] in ["Y", "y"]:
    print("Agreed.")
elif s[0] in ["N", "n"]:
    print("Declined.")
