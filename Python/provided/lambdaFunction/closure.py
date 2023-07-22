def comp(threshold):
    return lambda x: x < threshold

func_a = comp(10)
func_b = comp(20)

print(func_a(5), func_a(8), func_a(13), func_a(21))
print(func_b(5), func_b(8), func_b(13), func_b(21))