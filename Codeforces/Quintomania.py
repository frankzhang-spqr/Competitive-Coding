def is_perfect_melody(notes):
    for i in range(1, len(notes)):
        interval = abs(notes[i] - notes[i - 1])
        if interval not in {5, 7}:
            return False
    return True

t = int(input())
results = []

for _ in range(t):
    n = int(input())
    notes = list(map(int, input().split()))
    
    if is_perfect_melody(notes):
        results.append("YES")
    else:
        results.append("NO")

print("\n".join(results))