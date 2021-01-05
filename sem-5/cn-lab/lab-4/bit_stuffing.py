from typing import List

def bit_stuffing(bits: List[int]) -> List[int]:
    stuffed = []
    count = 0
    for i in range(len(bits)):
        if bits[i] == 1:
            count = count + 1
            stuffed.append(bits[i])
        else:
            count = 0
            stuffed.append(bits[i])
        if count == 5:
            stuffed.insert(i + 1, 0)

    return stuffed


input_bit = input("Enter input bits: ")


bits = [int(char) for char in input_bit]
print(bits)

stuffed = bit_stuffing(bits)
print(stuffed)
