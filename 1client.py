import xmlrpc.client
proxy=xmlrpc.client.ServerProxy('http://127.0.0.1:8000/')
print("\n\tMENU")
while(True):
    c=int(input("\n1.addition\n2.subtraction\n3.square\n4.factorial\n5.fibonacci\n6.Exit\nEnter your choice : "))
    if(c==1):
        print("--------------------")
        n=int(input("Num1 : "))
        m=int(input("Num2 : "))
        print("Addition of two numbers is : %s" % str(proxy.add(n,m)))
        print("--------------------")
    elif(c==2):
        print("--------------------")
        n=int(input("Num1 : "))
        m=int(input("Num2 : "))
        print("Subtraction of two numbers is : %s" % str(proxy.sub(n,m)))
        print("--------------------")
    elif(c==3):
        print("--------------------")
        n=int(input("Enter number : "))
        print("Square of number is : %s" % str(proxy.square(n)))
        print("--------------------")
    elif(c==4):
        print("--------------------")
        n=int(input("Enter number : "))
        print("Factorial of number is : %s" % str(proxy.fact(n)))
        print("--------------------")
    elif(c==5):
        print("--------------------")
        n=int(input("Enter number : "))
        print("Addition of two numbers is : %s" % str(proxy.fib(n)))
        print("--------------------")
    elif(c==6):
        print("--------------------")
        print("Exiting...")
        break
    else:
        print("Invalid")