class SetOperations:
    def __init__(self):
        self.s1 = {0}
        self.s2 = {0}

    def add(self):
        print("1.Enter Elements In Set 1\n2.Enter Elements in Set 2\n")
        choice = int(input("Enter Your Choice\n"))
        if choice == 1:
            element = int(input("Enter The Element to Be Added:"))
            self.s1.add(element)
            print(f"Element {element} is Added To Set 1")
        elif choice == 2:
            element = int(input("Enter The Element to Be Added:"))
            self.s2.add(element)
            print(f"Element {element} is Added To Set 2")

    def remove(self):
        print("1.Remove Elements In Set 1\n2.Remove Elements in Set 2\n")
        choice = int(input("Enter Your Choice\n"))
        if choice == 1:
            element = int(input("Enter The Element To Be Removed:"))
            self.s1.remove(element)
            print(f"\nElement {element} is Removed From Set 1\n")
        elif choice == 2:
            element = int(input("Enter The Element To Be Removed:"))
            self.s2.remove(element)
            print(f"Element {element} is Removed From Set 2")

    def display(self):
        print("1.Display Elements In Set 1\n2.Display Elements in Set 2\n")
        choice = int(input("Enter Your Choice\n"))
        if choice == 1:
            print("\n", self.s1)
        elif choice == 2:
            print("\n", self.s2)

    def search(self):
        print("1.Search Elements In Set 1\n2.Search Elements in Set 2\n")
        choice = int(input("Enter Your Choice\n"))
        if choice == 1:
            element = int(input("Enter The Element to Be Searched:"))
            if element in self.s1:
                print("\nElement Is Present\n")
        elif choice == 2:
            element = int(input("Enter The Element to Be Searched:"))
            if element in self.s2:
                print("\nElement Is Present\n")

    def length(self):
        print("\nLength Of The Set 1:\n", len(self.s1))
        print("\nLength Of The Set 2:\n", len(self.s2))

    def union_sets(self):
        print("\nUnion Of Two Set Is:")
        set3 = self.s1.union(self.s2)
        print("\n", set3)

    def intersection_sets(self):
        print("Intersection Of Two Set Is:")
        set3 = self.s1.intersection(self.s2)
        print("\n", set3)

    def symmetric_difference_sets(self):
        print("Symmetric Difference Of Two Set Is:")
        set3 = self.s1.symmetric_difference(self.s2)
        print("\n", set3)

    def subset_check(self):
        print("\nChecking If Set 1 Is Subset Of Set 2")
        if self.s1.issubset(self.s2):
            print("\nSet 2 Is Subset Of Set 1")
        else:
            print("\nSet 2 Is Not Subset Of Set 1")