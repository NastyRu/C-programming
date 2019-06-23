import ctypes
lib = ctypes.CDLL("./libarray.dll")

shift_array = lib.shift_array
shift_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
shift_array.restypes = ctypes.c_int

square = lib.square

squares_array = lib.squares_array
squares_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
squares_array.restypes = ctypes.c_int

def test_square():
    test = 0

    a = square(4)
    if 0 == a:
        test += 1
    else:
        print("Failed square function")

    a = square(66)
    if 1 == a:
        test += 1
    else:
        print("Failed square function")

    a = square(-25)
    if 1 == a:
        test += 1
    else:
        print("Failed square function")

    if 3 == test:
        return 0
    else:
        return 1


def test_squares_array(*err_cnt):
    test = 0

    array = [ 1, 2, 3, 4 ]
    src_len = len(array)
    src1 = (ctypes.c_int * src_len)(*array)
    src2 = (ctypes.c_int * src_len)(*array)
    kol = squares_array(src1, src2, 4)
    j = 0
    prov = [ 1, 4 ]
    for i in range(kol):
        if prov[i] == src2[i]:
            j += 1
    if 2 == j:
        test += 1
    else:
        print("Failed square_arrays function")
        return 1

    massiv = [ 2, 3, 5, 15 ]
    src_len = len(massiv)
    src1 = (ctypes.c_int * src_len)(*massiv)
    src2 = (ctypes.c_int * src_len)(*massiv)
    kol = squares_array(src1, src2, 4)
    if 0 == kol:
        test += 1
    else:
        print("Failed square_arrays function")

    if 2 == test:
        return 0
    else:
        return 1

def test_shift(*err_cnt):
    test = 0

    array = [ 1, 2, 3, 4, 5 ]
    prov = [ 4, 5, 1, 2, 3 ]
    src_len = len(array)
    src = (ctypes.c_int * src_len)(*array)
    shift_array(src, 5, 3)
    j = 0
    for i in range(src_len):
        if prov[i] == src[i]:
            j += 1
    if 5 == j:
        test += 1
    else:
        print("Failed shift_array function")

    j = 0
    shift_array(src, 5, 45)
    for i in range(src_len):
        if prov[i] == src[i]:
            j += 1
    if 5 == j:
        test += 1
    else:
        print("Failed shift_array function")

    if 2 == test:
        return 0
    else:
        return 1

def main():
    if (0 == test_square()) & (0 == test_shift()) & (0 == test_squares_array()):
        print("SUCCESS")


if __name__ == "__main__":
    main()
