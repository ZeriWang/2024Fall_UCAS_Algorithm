# Tower of Hanoi

# 运算汉诺塔移动次数
def hanoi_count(n):
    if n == 1:
        return 1
    return 2 * hanoi_count(n - 1) + 1

# 运算汉诺塔移动步骤
def hanoi(n, from_rod, to_rod, aux_rod):
    if n == 1:
        print(f"{from_rod} {to_rod}")
        return
    hanoi(n - 1, from_rod, aux_rod, to_rod)
    print(f"{from_rod} {to_rod}")
    hanoi(n - 1, aux_rod, to_rod, from_rod)

def main():
    n = int(input())
    move_count = hanoi_count(n)
    print(move_count)
    hanoi(n, '1', '3', '2')

if __name__ == "__main__":
    main()