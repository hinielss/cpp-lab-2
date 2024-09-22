def double_factorial(x):
    res = 1
    for i in range(x, 0, -2):
        res *= i
    return res


def get_t(x):
    s1 = sum(pow(x, 2 * k + 1) / double_factorial(2 * k + 1) for k in range(11))
    s2 = sum(pow(x, 2 * k) / double_factorial(2 * k) for k in range(11))
    return s1 / s2


def get_result(y):
    numerator = (7 * get_t(0.25) + 2 * get_t(1 + y))
    denominator = (6 - get_t(y * y - 1))
    return numerator / denominator


def run_tests():    
    f = open("tests.txt")
    for s in f:
        n, c_res = map(float, s.split())
        py_res = round(get_result(n), 6)
        assert py_res == c_res, f"{py_res, c_res}"
    f.close()


run_tests()
