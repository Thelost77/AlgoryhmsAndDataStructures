def powerFunc(number, power):
    if(power == 0):
        return 1;

    return (number * powerFunc(number, power - 1))

def sum(number):
    if(number == 1):
        return 1
    return powerFunc(number, number) + sum(number - 1)


print(powerFunc(4, 2))
print(sum(4))