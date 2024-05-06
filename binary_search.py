def binary_search(list, target):
    first = 0
    last = len(list) - 1

    while first <= last:
        midpoint = first + (last - first)//2

        if list[midpoint] == target:
            return midpoint
        
        elif list[midpoint] < target:
            first = midpoint + 1
        else:
            last = midpoint - 1    

    return None


def verify(index):
    if index is not None:
        print("Target found at index: ", index)
    else:
        print("Target not found")

def recursive_binary_search(list, target):
    if 0 == len(list):
        return False
    else:
        midpoint = (len(list))//2
        if target == list[midpoint]:
            return True
        else:
            if list[midpoint] < target:
                return recursive_binary_search(list[midpoint + 1:], target)
            else:
                return recursive_binary_search(list[:midpoint], target)

numbers = [1,2,3,4,5,6,7,8,9,10]
result = recursive_binary_search(numbers, 2)
verify(result)
