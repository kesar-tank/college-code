'''
Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up clients telephone number. Make use of two collision 
handling techniques and compare them using number of comparisons required to find a 
set of telephone numbers
'''
class Hash_Table:

    def __init__(self):
        self.m = int(input("Enter size of hash table:"))

        if self.m < 3:
            self.prime = self.m
        else:
            prime = [2, 3]
            for i in range(3,self.m):
                p=True
                for j in prime:
                    if i % j == 0:
                        p = False
                        break
                if p:
                    prime.append(i)
            self.prime = prime[-1]

    def hashfunc(self, a):
        return a % self.m

    def hashfunc2(self, a):
        return self.prime - (a % self.prime)

    def fill_linker_hash(self, l):
        self.hasht = [0] * self.m
        self.linkt = [-1] * self.m
        for i in l:
            temp = -1
            flag = False #indicator for collision

            index = self.hashfunc(i[1])
            if self.hasht[index] != 0:
                flag = True
                while self.linkt[index] != -1:
                    index = self.linkt[index]

                temp = index

                while self.hasht[index] != 0:
                    index = (index + 1) % self.m

            self.hasht[index] = i
            if flag:
                self.linkt[temp] = index
            print(self.hasht)
            print(self.linkt)

    def fill_double(self, l):
        self.doublehashing = [0] * self.m
        for i in l:
            c = 1 #no. of collisions
            index = self.hashfunc(i[1])
            while self.doublehashing[index] != 0:
                index = (self.hashfunc(i[1]) + c*self.hashfunc2(i[1])) % self.m
                c += 1
            self.doublehashing[index] = i


def check_rep(num):
    for i in entries:
            if num == i[1]:
                print("Number already in use")
                return False
    return True


hash = Hash_Table()
n = int(input("Enter number of data inputs: "))
entries = []
for i in range(n):
    d = []
    d.append(input("Enter name:"))
    tele = 0
    while (
        len(str(tele)) != 10
        or str(tele).isnumeric() == False
        or check_rep(tele) == False
    ):
        tele = int(input("Enter phonenumber:"))
    d.append(tele)
    entries.append(d)

while True:
    ch = int(input("1.Liner\n2.Double Hashing\n3.Exit\nEnter your choice:"))
    if ch == 1:
        hash.fill_linker_hash(entries)
        print("Linear probing")
        print("Hash table is ", hash.hasht)
        print("Linker list is ", hash.linkt)
    elif ch == 2:
        hash.fill_double(entries)
        print("Double Hashing")
        print("Hashing table is ", hash.doublehashing)
    elif ch == 3:
        print("Exiting")
        break
    