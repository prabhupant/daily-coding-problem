def majority_hash(arr):
    d = {}
    for i in arr:
        if i in d:
            count = d[i] + 1
            if count > len(arr)/2:
                print("majority element is ", i)
                return
            else:
                d[i] = count

def voting_algo(arr):
    maj_index = 0
    count = 1
    for i in range(1, len(arr)):
        if arr[i] == arr[maj_index]:
            count += 1
        else:
            count -= 1
        if count == 0:
            maj_index = i
            count = 1
    return arr[maj_index]

def check_majority(arr, maj_element):
    count = 0
    for i in arr:
        if i == maj_element:
            count += 1
        if count > len(arr)/2:
            return True
    return False

arr = [3,3,4,2,4,4,2,4,4]
max_element = voting_algo(arr)
if check_majority(arr, max_element):
    print(max_element)
else:
    print("No max element found!")

