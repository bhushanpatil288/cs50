import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print("usage:python dna.py databse sequence")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            for key in row:
                if key != "name":
                    row[key] = int(row[key])
            database.append(row)
        # print(database)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = file.read()
        # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence
    str_sequences = list(database[0].keys())[1:]
    # print(str_sequences)

    ans = {}
    for str in str_sequences:
        ans[str] = longest_match(sequence, str)

    # TODO: Check database for matching profiles

    for i in database:
        found = True
        for str in str_sequences:
            if i[str] != ans[str]:
                found = False
                break
        if found:
            print(i["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
