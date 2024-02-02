from setop import SetOperations
set_operations = SetOperations()
while True:
    print("***************MENU*************")
    print("1.Add\n2.Remove\n3.Display\n4.Search\n5.Length\n6.Union\n7.Intersection\n8.Symmetric Difference\n9.Subset\n10.Exit")
    choice = int(input("Enter Your Choice:"))

    if choice == 1:
        set_operations.add()
    elif choice == 2:
        set_operations.remove()
    elif choice == 3:
        set_operations.display()
    elif choice == 4:
        set_operations.search()
    elif choice == 5:
        set_operations.length()
    elif choice == 6:
        set_operations.union_sets()
    elif choice == 7:
        set_operations.intersection_sets()
    elif choice == 8:
        set_operations.symmetric_difference_sets()
    elif choice == 9:
        set_operations.subset_check()
    elif choice == 10:
        break
