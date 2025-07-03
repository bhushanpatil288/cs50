# names = ["Yullia", "David", "John"]

# name = input("Name: ")




# # for n in names:
# #     if name == n.lower():
# #         print("Found")
# #         break
# # else:
# #     print("Not Found")




# if name in names:
#     print("Found")
# else:
#     print("Not Found")








# people = [
#     {"name": "Yuliia", "number": "+1-617-495-1000"},
#     {"name": "David", "number": "+1-617-495-1000"},
#     {"name": "John", "number": "+1-949-468-2750"}
# ]

# name = input("Name: ")

# for person in people:
#     if person["name"] == name:
#         number = person["number"]
#         print(f"Found {number}")
#         break
# else:
#     print("Not Found")


people = {
    "Yuliia": "+1-617-495-1000",
    "David" : "+1-617-495-1000",
    "John" : "+1-949-468-2750"
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
