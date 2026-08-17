while True:
    str = input(">>> ")
    try:
        print(eval(str))
    except Exception as e:
        print(e)