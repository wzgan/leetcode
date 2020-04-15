# https://leetcode.com/problems/bulls-and-cows/

class Solution:
    def getHint1(self, secret: str, guess: str) -> str:
        bull = 0
        dict_guess = {}
        dict_secret = {}
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bull += 1
            else:
                if guess[i] in dict_guess:
                    dict_guess[guess[i]] += 1
                else:
                    dict_guess[guess[i]] = 1
                if secret[i] in dict_secret:
                    dict_secret[secret[i]] += 1
                else:
                    dict_secret[secret[i]] = 1

        cow = 0
        for k in dict_guess:
            if k in dict_secret:
                cow += min(dict_secret[k], dict_guess[k])

        ret = "%dA%dB" % (bull, cow)
        return ret

    def getHint2(self, secret: str, guess: str) -> str:
        bull = 0
        cow = 0
        dict_ch = {}
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bull += 1
            else:
                if secret[i] in dict_ch:
                    if dict_ch[secret[i]] < 0:
                        cow += 1
                    dict_ch[secret[i]] += 1
                else:
                    dict_ch[secret[i]] = 1
                if guess[i] in dict_ch:
                    if dict_ch[guess[i]] > 0:
                        cow += 1
                    dict_ch[guess[i]] -= 1
                else:
                    dict_ch[guess[i]] = -1

        ret = "%dA%dB" % (bull, cow)
        return ret


slt = Solution()
secret = "1123"
guess = "0111"
ret = slt.getHint2(secret, guess)
print(ret)