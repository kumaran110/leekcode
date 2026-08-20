class Solution:
    def getPermutation(self, n, k):
        numbers = list(range(1, n + 1))
        result = []

        # Convert k to 0-based index
        k -= 1

        # Precompute factorials
        factorial = [1] * (n + 1)

        for i in range(1, n + 1):
            factorial[i] = factorial[i - 1] * i

        for i in range(n, 0, -1):
            block_size = factorial[i - 1]

            index = k // block_size
            k = k % block_size

            result.append(str(numbers[index]))
            numbers.pop(index)

        return "".join(result)