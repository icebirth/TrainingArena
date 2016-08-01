# Imagine you landed a new job as a cashier...
# Your quirky boss found out that you're a programmer and has a weird request about something they've been wondering for a long time.

# Write a function that, given:

# an amount of money
# a list of coin denominations
# computes the number of ways to make amount of money with coins of the available denominations.
#
# Example: for amount=4 (4¢) and denominations=[1,2,3] (1¢, 2¢ and 3¢), your program would output 4—the number of ways to make 4¢ with those denominations:

# 1¢, 1¢, 1¢, 1¢
# 1¢, 1¢, 2¢
# 1¢, 3¢
# 2¢, 2¢


amount = 3
denominations = [1, 2, 3]

def find_ways_to_denominate(amount, denominates_list):
    if len(denominates_list) == 0:
        return 0
   
    if amount < denominates_list[0]:
        return 0
    elif amount == denominates_list[0]:
        return 1
    else:
        #print(amount, denominations)
        x = find_ways_to_denominate(amount-denominates_list[0], denominates_list[0:])
        #print ("x = ", x)
        y = find_ways_to_denominate(amount, denominates_list[1:])
        #print ("y = ", y)
        return x+y
    

# run your function through some test cases here
# remember: debugging is half the battle!
print find_ways_to_denominate(amount, denominations)
