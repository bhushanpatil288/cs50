text = str(input("Text: "))

letters = 0
words = 0
sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    if text[i] == " ":
        words += 1
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1

words += 1

L = (letters / words) * 100
S = (sentences / words) * 100

gradeLevel = (0.0588 * L) - (0.296 * S) - 15.8

if gradeLevel < 1:
    print("Before Grade 1")
elif gradeLevel >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(gradeLevel)}")
