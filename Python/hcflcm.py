m,n=int(input()),int(input())
mv=min(m,n)
for i in range (mv,0,-1):
    if(m%i==0 and n%i==0):
        gcd=i;break
print("HCF={} LCM={}".format(gcd,m*n//gcd))
