#include <cs50.h>
#include <stdio.h>

bool checkCardLength(long n);
int getCardLength(long n);
bool validateCard(long cardNumber, int cardLength);
string getCardType(long number);

int main(void)
{
    // check if card have valid length before card validation check
    long userCardNumber;
    while (true)
    {
        userCardNumber = get_long("Number: ");
        int length = getCardLength(userCardNumber);
        if (validateCard(userCardNumber, length) && checkCardLength(userCardNumber))
        {
            printf("%s", getCardType(userCardNumber));
            break;
        }
        else
        {
            printf("INVALID\n");
            break;
        }
    }
    return 0;
}

string getCardType(long number)
{
    int length = getCardLength(number);
    long firstTwo = number;
    while (firstTwo >= 100)
    {
        firstTwo /= 10;
    }

    if ((firstTwo == 34 || firstTwo == 37) && length == 15)
    {
        return "AMEX\n";
    }
    else if ((firstTwo >= 51 && firstTwo <= 55) && length == 16)
    {
        return "MASTERCARD\n";
    }
    else if ((firstTwo / 10 == 4) && (length == 13 || length == 16))
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}

bool validateCard(long cardNumber, int cardLength)
{
    int shouldDouble = false;
    int sum = 0;

    while (cardNumber > 0)
    {
        int digit = cardNumber % 10;

        if (shouldDouble)
        {
            int doubled = digit * 2;
            sum += (doubled > 9) ? (doubled % 10 + doubled / 10) : doubled;
        }
        else
        {
            sum += digit;
        }

        shouldDouble = !shouldDouble;
        cardNumber /= 10;
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// get card length

int getCardLength(long n)
{
    int length = 0;
    long number = n;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

// validate card length

bool checkCardLength(long n)
{
    int length = 0;
    long number = n;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    if (length == 15 || length == 16 || length == 13)
    {
        return true;
    }
    else
    {
        return false;
    }
}
