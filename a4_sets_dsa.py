'''
To create ADT that implement the "set" concept. 
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the value 
c. Contains (element) Return true if element is in collection, d. Size () Return number of 
values in collection Iterator () Return an iterator used to loop over collection, e. 
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset

'''
class Set:
    def __init__(self):
        self.arr = []

    def initialize_set(self):
        n = int(input("Enter the total no. of entries : "))
        for i in range(n):
            val = int(input("Enter the value to add : "))
            self.Add(val)

    def Add(self, val):
        if val not in self.arr:
            self.arr.append(val)

    def Remove(self, val):
        if val in self.arr:
            self.arr.remove(val)
            print("Element removed")
        else:
            print("Element not found")

    def Iterator(self):
        return iter(self.arr)

    def Contains(self, val):
        return val in self.arr

    def Size(self):
        return len(self.arr)

    def Intersection(self, lst):
        temp = []
        for i in lst:
            if i in self.arr:
                temp.append(i)
        return (temp)

    def Union(self, lst):
        temp = self.arr.copy()
        for i in lst:
            if i not in self.arr:
                temp.append(i)
        return (temp)

    def Difference(self, lst):
        temp = self.arr.copy()
        for i in lst:
            if i in self.arr:
                temp.remove(i)
        return (temp)

    def subset(self, lst):
        flag = True
        for i in lst:
            if i not in self.arr:
                return False
        return True

    def display(self):
        return("{"+ str(self.arr)[1:-1]+"}")


obj1 = Set()
while True:
    print("\n*****MENU*****")
    print("1.Add element")
    print("2.Remove element")
    print("3.Check if element is present")
    print("4.Size of set")
    print("5.Iterator for set")
    print("6.Intersection for set")
    print("7.Union for set")
    print("8.Difference for set")
    print("9.Check subset")
    print("10.Display set")
    print("11.Exit")
    ch = int(input("Enter your choice:"))

    if ch == 1:
        n = int(input("Enter the total no. of enteries : "))
        for i in range(n):
            val = int(input("Enter the value to add : "))
            obj1.Add(val)
        print("Element added...")

    elif ch == 2:
        print(obj1.display())
        val = int(input("Enter the value to remove : "))
        if(obj1.Remove(val)):
            print(obj1.display())

    elif ch == 3:
        val = int(input("Enter the value to search : "))
        if obj1.Contains(val):
            print("Element present")
        else:
            print("Element absent")

    elif ch == 4:
        print("Size of list is - ",obj1.Size())

    elif ch == 5:
        iterator = obj1.Iterator()
        for i in range(obj1.Size()):
            print(next(iterator))

    elif ch == 6:
        obj2 = Set()
        obj2.initialize_set()
        print("Intersection of sets is : ",obj1.Intersection(obj2.arr))
        

    elif ch == 7:
        obj2 = Set()
        obj2.initialize_set()
        print("Union of sets is : ",obj1.Union(obj2.arr))
        

    elif ch == 8:
        obj2 = Set()
        obj2.initialize_set()
        print("Difference of sets is : ",obj1.Difference(obj2.arr))
        

    elif ch == 9:
        obj2 = Set()
        obj2.initialize_set()    
        if obj1.subset(obj2.arr):
            print("Subset present")
        else:
            print("Subset absent")

    elif ch == 10:
        print("Set is : ",obj1.display())

    elif ch == 11:
        print("Exiting")
        break
