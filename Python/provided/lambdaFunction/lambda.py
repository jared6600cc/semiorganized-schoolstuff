a = [10, 'number',11.2]
a.sort(key=lambda x: x.__class__.__name__)
print(a)