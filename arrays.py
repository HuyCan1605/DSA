new_list = [1, 2, 3]

result = new_list[0]

if 1 in new_list: print(True)

for n in new_list:
    if 1 == n: 
        print(True)
        break

new_list.append(4)
new_list.append(244) 

new_list.extend([3, 5, 2, 5,6,5])