# Xiaoyan Wang 10/14/2018
from sys import stdin


def isvalid(isbn):
    isbn = isbn.replace("-", "")  # remove whitespaces and hypens
    s1 = s2 = 0
    position = 1
    for c in isbn:
        if c.isdigit():
            if position > 10:
                return False
            s1 += int(c)
            s2 += s1
            position += 1
        elif c == 'X' and position == 10:
            s1 += 10
            s2 += s1
            position += 1
        else:
            return False
    # print('position = {}, s2 = {}'.format(position, s2))
    return position == 11 and s2 % 11 == 0


for isbn in stdin:
    isbn = isbn.strip()
    print("{} is correct.".format(isbn) if isvalid(
        isbn) else "{} is incorrect.".format(isbn))
