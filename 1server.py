from xmlrpc.server import SimpleXMLRPCServer

def add(n,m):
    print("- Request for addition of numbers ",n," and ",m,"\n")
    return n+m

def sub(n,m):
    print("- Request for subtraction of numbers ",n," and ",m,"\n")
    return n-m

def square(n):
    print("- Request for square of number ",n,"\n")
    return n*n

def fib(n):
    print("- Request for fibonacii numbers upto ",n,"\n")
    ans=[]
    for i in range (0,n):
        if i==0 or i==1:
            ans.append(i)
        else:
            ans.append(ans[len(ans)-1]+ans[len(ans)-2])
    return ans

def fact(n):
    print("- Request for factorial of number ",n,"\n")
    if n==1 or n==0:
        return 1
    return n*fact(n-1)

port=8000
server=SimpleXMLRPCServer(("127.0.0.1",port),logRequests=False)
server.register_function(fact,'fact')
server.register_function(add,'add')
server.register_function(sub,'sub')
server.register_function(fib,'fib')
server.register_function(square,'square')

try:
    print("Server listening on port : ",port)
    server.serve_forever()
except:
    print("Exit")
