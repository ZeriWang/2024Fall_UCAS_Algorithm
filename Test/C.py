def parse_number(s):
    if s.startswith('0x') or s.startswith('0X'):
        return int(s, 16)  # 16 进制
    elif s.startswith('0'):
        return int(s, 8)   # 8 进制
    else:
        return int(s, 10)  # 10 进制

def main():
    a = input()
    b = input()

    a_int = parse_number(a)
    b_int = parse_number(b)

    result = a_int + b_int

    print(f"{result}")

if __name__ == "__main__":
    main()