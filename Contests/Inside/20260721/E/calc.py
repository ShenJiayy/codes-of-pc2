while True:
    s = input(">> ")
    if s == "exit":
        break
    try:
        exec(s)
    except Exception as e:
        print(e)