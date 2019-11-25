import random


def numguess(try_cnt=5, ans=random.randint(1, 10)):
    while 1:
        if try_cnt == 0:
            print('fail. ans = {}'.format(ans))
            break

        guess = in_guess()
        if guess == ans:
            print('success')
            break
        elif guess > ans:
            print('down')
            try_cnt -= 1
        else:
            print('up')
            try_cnt -= 1


def in_guess():
    try:
        guess = int(input('guess :'))
        return guess
    except:
        print(MyError())
        return in_guess()


class MyError(Exception):
    def __str__(self):
        return "Custom Error"


numguess()
