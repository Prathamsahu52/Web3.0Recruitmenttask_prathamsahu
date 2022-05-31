import hashlib
import time

a_string=input("Enter string inside quotes: ")

start_t=time.time()
hashed_string = hashlib.sha256(a_string.encode()).hexdigest()
target='0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF'

n=0


while(int(hashed_string,16)>=int(target,16)):
    b_string=a_string+str(n)
    n=n+1
    hashed_string = hashlib.sha256(b_string.encode()).hexdigest()
    

print("hashed ", hashed_string)
print("nonce ",n-1)
end_t=time.time()

print("time taken ",end_t-start_t)
