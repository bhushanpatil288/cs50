# import csv

# file = open("phonebook2.csv", "a")

# name = input("Name: ")
# number = input("Number: ")

# writer = csv.writer(file)
# writer.writerow([name, number])

# file.close()



# more compact version
# no file.close, with as file, indentation

import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook2.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, number])
