class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        Mapping = {}
        covered = set()
        for i in range(len(s)):
            if s[i] not in Mapping.keys():
                if t[i] not in covered:
                    Mapping[s[i]] = t[i]
                    covered.add(t[i])
                else:
                    return False
            elif Mapping[s[i]] != t[i]:
                return False
        return True

