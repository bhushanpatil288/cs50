import cs50

scores = []

for i in range(3):
    score = cs50.get_int("Score: ")
    scores.append(score)            # or scores += [score]

average = sum(scores) / len(scores)
print(f"Average: {average}")
