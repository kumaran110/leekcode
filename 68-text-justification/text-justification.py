class Solution:
    def fullJustify(self, words, maxWidth):
        result = []
        i = 0

        while i < len(words):
            line_words = []
            line_length = 0

            # Select words for the current line
            while i < len(words):
                if line_length + len(words[i]) + len(line_words) <= maxWidth:
                    line_words.append(words[i])
                    line_length += len(words[i])
                    i += 1
                else:
                    break

            # Last line or line with only one word
            if i == len(words) or len(line_words) == 1:
                line = " ".join(line_words)
                line += " " * (maxWidth - len(line))
                result.append(line)
                continue

            # Fully justify the line
            spaces = maxWidth - line_length
            gaps = len(line_words) - 1

            extra = spaces // gaps
            remainder = spaces % gaps

            line = ""

            for j in range(gaps):
                line += line_words[j]
                line += " " * (extra + (1 if j < remainder else 0))

            line += line_words[-1]
            result.append(line)

        return result