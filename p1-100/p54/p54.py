# rank each player's hand, if equal,
# rank the hand not containing the set
# which afforded the win
def winner(h1, h2):
    r1 = rank(h1)
    r2 = rank(h2)
    if r1[0] == r2[0]: return winner(r1[1], r2[1])
    return 0 if r1[0] > r2[0] else 1

"""
Ranks:

"""
def rank(h):
    if not h: return -1



if __name__ == "__main__":
    h1 = ['5H', '5C', '6S', '7S', 'KD']
    h2 = ['2C', '3S', '8S', '8D', 'TD']
