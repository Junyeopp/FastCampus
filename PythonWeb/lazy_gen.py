import time

def lazy_evaluation(n):
    print("1 sec")
    time.sleep(1)
    return n

n_list = [lazy_evaluation(n) for n in range(1,6)]
print("---")
for i in n_list:
    print(i)

n_gen = (lazy_evaluation(n) for n in range(1,6))
print("---")
for i in n_gen:
    print(i)