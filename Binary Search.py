def binary_search(my_list, target): #assuming the list is already sorted.
    low = 0
    high = len(my_list) -1

    while low <= high: #loop to search as long as there are elements to search
        mid = (low + high) // 2 #calculate middle index
        if my_list[mid] == target: #check if middle value is target
            return mid
        elif my_list[mid] < target: #if mid is less than target,search right half
            low = mid + 1 #updating low to search right half only
        else: #if mid is greater than target, search left half
            high = mid - 1 # update high to search left half only

    return "target not found" # if loop ends without finding the target in the list return this

print(binary_search([2,5,8,12,16], 1)) #sample input to test function
