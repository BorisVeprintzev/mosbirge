def main():
    string = input("Input string:")
    ans = ""
    count = 0
    tmp = string[0]
    for char in string:
        if tmp == char:
            count += 1
        else:
            if count > 1:
                ans += str(count) + tmp
            else:
                ans += tmp
            count = 1
        tmp = char
    if count > 1:
        ans += str(count) + tmp
    else:
        ans += tmp
    print(ans)

if __name__ == "__main__":
    main()