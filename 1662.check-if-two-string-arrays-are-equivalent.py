#
# @lc app=leetcode id=1662 lang=python3
#
# [1662] Check If Two String Arrays are Equivalent
#

# @lc code=start
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        word1_index,word2_index = 0,0
        i,j = 0,0
        while word2_index < len(word2) and word1_index < len(word1):
            if i < len(word1[word1_index]) and j < len(word2[word2_index]):
                if word1[word1_index][i] == word2[word2_index][j]:
                    i+=1
                    j+=1
                else:
                    return False
            else:
                if not i < len(word1[word1_index]):
                    i = 0
                    word1_index+=1
                else:
                    j = 0
                    word2_index +=1
        return True  
        
# @lc code=end

