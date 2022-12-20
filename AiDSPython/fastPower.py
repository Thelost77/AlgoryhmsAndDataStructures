import time;

def quickPow(number, power):
    if(power == 0):
        return 1;
    if(power % 2 == 1):
        return number * quickPow(number, power - 1)

    y = quickPow(number, power / 2)
    return y * y;

def powerFunc(number, power):
    if(power == 0):
        return 1;

    return (number * powerFunc(number, power - 1))


startOfQuickPow = time.time();

quickPow(2, 800);

endOfQuickPow = time.time();
print(f"Quick Power has taken {endOfQuickPow - startOfQuickPow}")

startOfPow = time.time();

powerFunc(2, 800);

endOfPow = time.time();
print(f"Power has taken {endOfPow - startOfPow}")

print(f"Quick Power is {(endOfPow - startOfPow)/(endOfQuickPow - startOfQuickPow)} faster")