# def main():
#     n = int(input("Enter the number of bricks: "))
#     printBricks(n)

# def printBricks(n):
#     for i in range(n):
#         print("#")

# main()



# # CS50 VERSIONS
# import cs50
# while True:
#     n = cs50.get_int("Height: ")
#     if n > 0:
#         break

# for i in range(n):
#     print("#")




# for i in range(4):
#     print("?", end="")
# print()

# print("?" * 4)  #pythonic way


for i in range(3):
    for j in range(3):
        print("#", end="")
    print()
