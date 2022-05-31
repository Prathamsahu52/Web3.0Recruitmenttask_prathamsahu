import hashlib
import time

a_string=input("Enter string inside quotes: ")

start_t=time.time()
hashed_string = hashlib.sha256(a_string.encode('utf-8')).hexdigest()
target='0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF'

n=0


while(int(hashed_string,16)>=int(target,16)):
    a_string=a_string+str(n)
    n=n+1
    hashed_string = hashlib.sha256(a_string.encode('utf-8')).hexdigest()
    

print(hashed_string)
print(n)
end_t=time.time()

print(end_t-start_t)
