# problem link -> https://www.hackerrank.com/challenges/nested-list/

if __name__ == '__main__':
    scores = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        scores.append([name, score])
    second = sorted(set([score for name, score in scores]))[1]
    print('\n'.join(sorted([name for name, score in scores if score == second])))

