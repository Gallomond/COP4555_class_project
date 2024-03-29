def bubble_sort(my_list): #function takes in a list 
    for i in range(len(my_list) -1, 0 ,-1): #reduces length of list every loop since the last number is 'sorted'
        for j in range(i): #loop moves forward through the list
            if my_list[j] > my_list[j+1]: #if current number greater than the next,swap them.
                temp = my_list[j]
                my_list[j] = my_list[j+1]
                my_list[j+1] = temp
    return my_list #returns sorted list

print(bubble_sort([4,2,6,5,1,3])) #sample input to test function            