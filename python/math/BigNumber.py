class BigNumber:
    def __init__(self):
        self._digits = []

    def push(self, digit):
        self._digits.append(digit)

    @property
    def num_digits(self):
        return len(self._digits)

    def __repr__(self):
        return "".join(map(lambda d: str(d), reversed(self._digits)))

    
    def __eq__(self, value):
        return NotImplementedError

    def __gt__(self, value):
        return NotImplementedError

    def __ge__(self, value):
        return NotImplementedError

    def sum(self, num):
        result = BigNumber()
        # FIXME: when numbers has same digits lower_mun = bigger num 
        lower_num = min(self, num, key=lambda n: n.num_digits)
        bigger_num = max(self, num, key=lambda n: n.num_digits)
        carry = 0

        for i in range(bigger_num.num_digits):
            if i<lower_num.num_digits:
                r = lower_num._digits[i] + bigger_num._digits[i] + carry
            else:
                r = bigger_num._digits[i] + carry
            carry = r//10
            r = r%10
            result.push(r)


        return result



if __name__ == "__main__":
    x = BigNumber()
    for i in [1,1,1,1]:
        x.push(i)

    y = BigNumber()
    for i in [9,2,3,9]: y.push(i)

    print("{} + {} = {}".format(x, y, x.sum(y)))