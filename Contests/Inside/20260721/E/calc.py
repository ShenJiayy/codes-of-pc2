while True:
    s = input(">> ")
    if s == "exit":
        break
    try:
        print(eval(s))
    except Exception as e:
        print(e)