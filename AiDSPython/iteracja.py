from traceback import print_tb


def fun(par1, *par, **keypar):
    print("first:", par1)

    for i in par:
        print(i, end="\n")

    for key in keypar:
        print(key, ":", keypar[key], end=" ")

fun(1, 1, 1 ,1 , 1, 1, 1 ,1, klucz="bebok")